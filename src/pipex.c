/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:51:44 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/14 22:55:12 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	open_file(char *fname, int flag_type)
{
	int		fd;
	int		flags;

	flags = 0;
	if (flag_type == R_LEFT)
		flags = O_RDONLY;
	else if (flag_type == R_RIGHT)
		flags = O_CREAT | O_WRONLY | O_TRUNC;
	else if (flag_type == R_DRIGHT)
		flags = O_CREAT | O_WRONLY | O_APPEND;
	fd = open(fname, flags, S_IREAD | S_IWRITE);
	return (fd);
}

static int	here_doc(t_param *param)
{
	int		doc;
	char	*line;

	doc = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	if (doc == -1)
		exit_error("p1", param->file_in);
	write(1, "> ", 2);
	line = get_next_line(1);
	while (line)
	{
		if (!ft_strcmp(line, param->limiter))
			break ;
		write(doc, line, ft_strlen(line));
		write(doc, "\n", 1);
		write(1, "> ", 2);
		line = get_next_line(1);
	}
	close(doc);
	doc = open("here_doc", O_RDONLY);
	return (doc);
}

static void	redirect_left(t_param *param, int i)
{
	int		fd;

	if (param->cmd[i].type == R_DLEFT)
		fd = here_doc(param);
	else
		fd = open_file(param->file_in, R_LEFT);
	if (fd == -1)
		exit_error("pipex: ", param->file_in);
	if (dup2(fd, STDIN_FILENO) == -1)
		exit_error("p3", "dup2");
	if (dup2(param->cmd[i].pipe[SIDE_OUT], STDOUT_FILENO) == -1)
		exit_error("p4", "dup2");
}

static void	redirect_right(t_param *param, int i)
{
	int		fd;

	fd = open_file(param->file_out, param->cmd[i].type);
	if (fd == -1)
		exit_error("p5", param->file_out);
	if (dup2(fd, STDOUT_FILENO) == -1)
		exit_error("p6", "dup2");
	if (dup2(param->cmd[i - 1].pipe[SIDE_IN], STDIN_FILENO) == -1)
		exit_error("p7", "dup2");
}

void	pipex(t_param *param, int i)
{
	int		type;

	type = param->cmd[i].type;
	if (type == R_LEFT || type == R_DLEFT)
		redirect_left(param, i);
	else if (type == R_RIGHT || type == R_DRIGHT)
		redirect_right(param, i);
	else if (type == PIPE)
	{
		if (dup2(param->cmd[i].pipe[SIDE_OUT], STDOUT_FILENO) == -1)
			exit_error("p8", "dup2");
		if (dup2(param->cmd[i - 1].pipe[SIDE_IN], STDIN_FILENO) == -1)
			exit_error("p9", "dup2");
	}
	close(param->cmd[i].pipe[SIDE_OUT]);
	close(param->cmd[i].pipe[SIDE_IN]);
	if (param->cmd[i].path == NULL)
	{
		errno = 0;
		exit_error(param->cmd[i].arg[0], ": command not found");
	}
}
