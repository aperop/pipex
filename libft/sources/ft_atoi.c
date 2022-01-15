/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 00:35:06 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/09 13:54:24 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	size_t	number;

	number = 0;
	sign = 1;
	i = 0;
	if (!*str)
		return (0);
	while (*(str + i) == ' ' || (*(str + i) >= '\t' && *(str + i) <= '\r'))
		i++;
	if (*(str + i) == '-')
		sign = -1;
	if (*(str + i) == '+' || *(str + i) == '-')
		i++;
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		number = number * 10 + *(str + i) - '0';
		i++;
	}
	if (number > 2147483648)
		return (-1 + (sign < 0 && number > 2147483648));
	return (sign * number);
}
