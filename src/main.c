/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:51:41 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/10 01:30:51 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_empty(char ***cmd)
{
	char	**emty;

	emty = ft_calloc(sizeof(char *), 2);
	if (!emty)
		exit_error_arg("m1", ERR_MEM);
	emty[0] = ft_strdup("");
	if (!emty[0])
		exit_error_arg("m2", ERR_MEM);
	free_array(*cmd);
	*cmd = emty;
}

static t_cmd	*init_cmd(char **argv, size_t size, int start)
{
	t_cmd		*cmd;
	size_t		i;

	cmd = malloc(size * sizeof(t_cmd));
	if (!cmd)
		exit_error_arg("m3", ERR_MEM);
	i = 0;
	while (i < size)
	{
		cmd[i].arg = ft_split(argv[i + start], ' ');
		if (!cmd[i].arg)
			exit_error_arg("m4", ERR_MEM);
		if (!cmd[i].arg[0])
			init_empty(&cmd[i].arg);
		if (i == 0)
			cmd[i].type = R_LEFT;
		else if (i == size - 1)
			cmd[i].type = R_RIGHT;
		else
			cmd[i].type = PIPE;
		i++;
	}
	return (cmd);
}

static void	save_args(t_param *param, int argc, char **argv)
{
	if (argc > 1 && ft_strcmp(argv[1], "here_doc") == 0)
	{
		if (argc != 6)
			exit_error_arg(ERR_ARG1, ERR_ARG2);
		param->limiter = argv[2];
		param->size = 2;
		param->cmd = init_cmd(argv, param->size, 3);
		param->cmd[0].type = R_DLEFT;
		param->cmd[1].type = R_DRIGHT;
		param->file_in = argv[1];
		param->file_out = argv[5];
	}
	else
	{
		if (argc < 5)
			exit_error_arg(ERR_ARG1, ERR_ARG2);
		param->limiter = NULL;
		param->size = argc - 3;
		param->file_in = argv[1];
		param->file_out = argv[argc - 1];
		param->cmd = init_cmd(argv, param->size, 2);
	}
}

static void	free_param(t_param *param)
{
	size_t	i;

	i = 0;
	while (i < param->size)
	{
		free_array(param->cmd[i].arg);
		ft_free(&param->cmd[i].path);
		i++;
	}
	free(param->cmd);
	free(param);
}

int	main(int argc, char const **argv, char **env)
{
	t_param	*param;

	param = malloc(sizeof(t_param));
	if (!param)
		exit_error_arg("m7", ERR_MEM);
	save_args(param, argc, (char **)argv);
	execute_commands(param, env);
	if (param->limiter)
		unlink("here_doc");
	free_param(param);
	return (0);
}
