/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:57:42 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/09 00:23:01 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Функция ft_itoa распределяет (с помощью malloc) и возвращает «свежую» строку,
заканчивающуюся на \0, представляющую целое число n,
заданное в качестве аргумента. Подерживаются отрицательные числа.
Если распределение завершается неудачно, функция возвращает NULL.
*/
#include "../includes/libft.h"
#include <stdio.h>

static unsigned int	counts(int n)
{
	unsigned int	count;

	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_writetoptr(int n, unsigned int len, char *str)
{
	while (n)
	{
		*(str + len) = n % 10 + '0';
		n /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char			*str;
	int				sign;
	unsigned int	len;

	sign = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
	{
		n *= -1;
		sign = -1;
	}
	len = (sign < 0) + counts(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	*(str + len) = '\0';
	len--;
	if (sign < 0)
		*str = '-';
	ft_writetoptr(n, len, str);
	return (str);
}
