/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:52:42 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/10 01:32:00 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>

# define ERR_MEM	"Memory allocation error"
# define ERR_ARG1	"pipex: Usage:\t./pipex [FILE] [COMMAND]... [FILE]\n\t"
# define ERR_ARG2	"or:\t./pipex here_doc [LIMITER] [COMMAND] [COMMAND] [FILE]"

# define SIDE_OUT 1
# define SIDE_IN 0

# define R_LEFT 1
# define R_RIGHT 2
# define R_DRIGHT 3
# define R_DLEFT 4
# define PIPE 5

typedef struct s_cmd
{
	char	**arg;
	char	*path;
	int		type;
	int		pipe[2];
	pid_t	pid;
	size_t	size;
}	t_cmd;

typedef struct s_param
{
	t_cmd	*cmd;
	char	*file_in;
	char	*file_out;
	char	*limiter;
	size_t	size;
}	t_param;

void	ft_free(char **str);
char	**free_array(char **array);
void	exit_error(char *s);
void	exit_error_arg(char *msg, char *arg);
void	execute_commands(t_param *param, char **env);
char	*get_env_value(char *name, char **env);
void	pipex(t_param *param, int i);

#endif
