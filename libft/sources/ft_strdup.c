/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 14:59:05 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/15 14:43:56 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s1len;
	char	*cp;

	s1len = ft_strlen(s1) + 1;
	cp = (char *)malloc(s1len * sizeof(char));
	if (cp == 0)
		return (cp);
	ft_strlcpy(cp, s1, s1len);
	return (cp);
}
