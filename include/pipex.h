/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:52:42 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/15 14:58:02 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/includes/libft.h"
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>

# define ERR_MEM	"Memory allocation error"
# define ERR_ARG1	"pipex: Usage:\t./pipex [FILE] [COMMAND]... [FILE]\n\t"
# define ERR_ARG2	"or:\t./pipex here_doc [LIMITER] [COMMAND] [COMMAND] [FILE]"

enum e_side
{
	SIDE_IN,
	SIDE_OUT
};

enum e_redirect
{
	R_LEFT,
	R_RIGHT,
	R_DLEFT,
	R_DRIGHT,
	PIPE
};

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

void	free_path(char **str);
char	**free_array(char **array);
void	exit_error(char *msg, char *arg);
void	execute(t_param *param, char **env);
char	*get_path_value(char *name, char **env);
void	free_struct(t_param *param);
void	pipex(t_param *param, int i);

#endif
