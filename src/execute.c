/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:51:34 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/15 13:47:02 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*set_path(char *path, char *cmd)
{
	char	*res;
	char	*tmp;

	if (!cmd[0])
		return (NULL);
	if (cmd[0] == '.' || cmd[0] == '/')
		res = ft_strdup(cmd);
	else
	{
		tmp = ft_strjoin(path, "/");
		res = ft_strjoin(tmp, cmd);
		free(tmp);
	}
	if (!res)
		exit_error("", ERR_MEM);
	if (!access(res, 1))
		return (res);
	else
		free(res);
	return (NULL);
}

static void	get_path_to_cmd(t_param *param, char **env)
{
	char	*path;
	char	**path_array;
	size_t	i;
	int		j;

	path = get_path_value("PATH", env);
	path_array = ft_split(path, ':');
	if (!path_array)
		exit_error("", ERR_MEM);
	free_path(&path);
	i = -1;
	while (++i < param->size)
	{
		j = -1;
		while (path_array[++j])
		{
			param->cmd[i].path = set_path(path_array[j], param->cmd[i].arg[0]);
			if (param->cmd[i].path)
				break ;
		}
	}
	free_array(path_array);
}

static void	close_fd(t_param *param, int i)
{
	close(param->cmd[i].pipe[SIDE_OUT]);
	if (param->cmd[i].type != R_LEFT)
		close(param->cmd[i - 1].pipe[SIDE_IN]);
	if (param->cmd[i].type == R_RIGHT || param->cmd[i].type == R_DRIGHT)
		close(param->cmd[i].pipe[SIDE_IN]);
}

void	execute(t_param *param, char **env)
{
	size_t	i;

	get_path_to_cmd(param, env);
	i = 0;
	while (i < param->size)
	{
		if (pipe(param->cmd[i].pipe) == -1)
			exit_error("", "Pipe error!");
		param->cmd[i].pid = fork();
		if (param->cmd[i].pid == -1)
			exit_error("", "Fork error!");
		else if (param->cmd[i].pid == 0)
		{
			pipex(param, i);
			execve(param->cmd[i].path, param->cmd[i].arg, env);
		}
		else
			close_fd(param, i);
		i++;
	}
	while (i--)
		wait(NULL);
}
