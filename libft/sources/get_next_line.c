/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 04:50:57 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/09 20:56:25 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	count1;
	size_t	count2;
	char	*s;

	if (!s1 || !s2)
		return (0);
	s = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*s));
	if (!s)
		return (0);
	count1 = 0;
	count2 = 0;
	while (*(s1 + count1))
	{
		*(s + count1) = *(s1 + count1);
		count1++;
	}
	while (*(s2 + count2))
		*(s + count1++) = *(s2 + count2++);
	*(s + count1) = '\0';
	free(s1);
	return (s);
}

static char	*ft_get_str(char	*stat_str)
{
	char	*str;
	int		index;

	index = 0;
	if (!*stat_str)
		return (NULL);
	while (*(stat_str + index) && *(stat_str + index) != '\n')
		index++;
	str = (char *)malloc(sizeof(*str) * (index + 2));
	if (!str)
		return (NULL);
	index = 0;
	while (*(stat_str + index) && *(stat_str + index) != '\n')
	{
		*(str + index) = *(stat_str + index);
		index++;
	}
	*(str + index) = '\0';
	return (str);
}

static char	*ft_remainder(char	*stat_str)
{
	char	*str;
	int		count;
	int		index;

	index = 0;
	count = 0;
	while (*(stat_str + index) && *(stat_str + index) != '\n')
		index++;
	if (!*(stat_str + index))
	{
		free(stat_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(*str) * (ft_strlen(stat_str) - index + 1));
	if (!str)
		return (NULL);
	index++;
	while (*(stat_str + index))
		*(str + (count++)) = *(stat_str + (index++));
	*(str + count) = '\0';
	free(stat_str);
	return (str);
}

static char	*ft_read_buf(int fd, char *stat_str)
{
	char		*buffer;
	ssize_t		read_bytes;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(*buffer));
	if (!buffer)
		return (NULL);
	read_bytes = 1;
	while (read_bytes != 0 && !ft_strchr(stat_str, '\n'))
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		*(buffer + read_bytes) = '\0';
		if (!stat_str)
		{
			stat_str = (char *)malloc(1 * sizeof(*stat_str));
			*stat_str = '\0';
		}
		stat_str = ft_strjoin_free(stat_str, buffer);
	}
	free(buffer);
	return (stat_str);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*stat_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stat_str = ft_read_buf(fd, stat_str);
	if (!stat_str)
		return (NULL);
	str = ft_get_str(stat_str);
	stat_str = ft_remainder(stat_str);
	return (str);
}
