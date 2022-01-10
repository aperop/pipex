/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:51:48 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/10 01:53:00 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char **str)
{
	if (!*str)
		return ;
	free(*str);
	*str = NULL;
}

char	**free_array(char **array)
{
	size_t		i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

void	exit_error(char *s)
{
	ft_putstr_fd("./pipex: ", STDERR_FILENO);
	if (errno)
		perror(s);
	else
		ft_putendl_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	exit_error_arg(char *msg, char *arg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	if (errno)
		perror(arg);
	else
		ft_putendl_fd(arg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

char	*get_env_value(char *name, char **env)
{
	int		i;
	char	*eq;
	char	*value;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], name, ft_strlen(name)))
		{
			eq = ft_strchr(env[i], '=');
			if (eq)
			{
				value = ft_strdup(eq + 1);
				if (!value)
					exit_error(ERR_MEM);
				return (value);
			}
		}
		i++;
	}
	return (NULL);
}
