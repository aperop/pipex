/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:13:06 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/15 14:44:27 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*(haystack + i))
	{
		j = 0;
		while ((i + j) < len && *(haystack + i + j) == *(needle + j))
		{
			if (!*(haystack + i + j) && !*(needle + j))
				return ((char *)(haystack + i));
			j++;
		}
		if (!*(needle + j))
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
