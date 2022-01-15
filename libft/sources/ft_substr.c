/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:59:14 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/15 14:44:41 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	slen;
	size_t	sublen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	sublen = 0;
	if (start < slen)
		sublen = slen - start;
	if (sublen > len)
		sublen = len;
	sub = (char *)malloc((sublen + 1) * sizeof(char));
	if (!sub)
		return (sub);
	ft_strlcpy(sub, s + start, sublen + 1);
	return (sub);
}
