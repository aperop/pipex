/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:06:13 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/15 14:44:06 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	count;

	len = 0;
	count = 0;
	while (len < size && *(dst + len))
		len++;
	while (*(src + count) && (len + count + 1) < size)
	{
		*(dst + len + count) = *(src + count);
		count++;
	}
	if (len < size)
		*(dst + len + count) = '\0';
	while (*(src + count))
		count++;
	return (len + count);
}
