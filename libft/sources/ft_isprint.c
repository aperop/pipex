/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhawkgir <dhawkgir@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 15:09:24 by dhawkgir          #+#    #+#             */
/*   Updated: 2022/01/09 00:23:01 by dhawkgir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Функция isprint возвращает ненулевое значение,
если аргумент c является печатным символом, включая пробел;
в противном случае возвращается 0.
Значения печатных символов находятся в пределах от 32 до 126.
*/
#include "../includes/libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}