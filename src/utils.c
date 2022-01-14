/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 20:51:48 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/15 00:03:15 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_path(char **str)
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

void	exit_error(char *msg, char *arg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	if (errno)
		perror(arg);
	else
		ft_putendl_fd(arg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

char	*get_path_value(char *name, char **env)
{
	int		i;
	char	*tmp;
	char	*value;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], name, ft_strlen(name)))
		{
			tmp = ft_strchr(env[i], '=');
			if (tmp)
			{
				value = ft_strdup(tmp + 1);
				if (!value)
					exit_error("u1", ERR_MEM);
				return (value);
			}
		}
		i++;
	}
	return (NULL);
}
