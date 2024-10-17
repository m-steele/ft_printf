/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:06:46 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/17 14:02:02 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

char	*ft_itolowhex(unsigned long num)
{
	char			*str;
	char			*hex;
	unsigned long	x;
	int				len;

	hex = "0123456789abcdef";
	x = num;
	len = 0;
	while (x)
	{
		x /= 16;
		len++;
	}
	if (num == 0)
		len = 1;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	str[len] = '\0';
	while (len--)
	{
		str[len] = hex[num % 16];
		num /= 16;
	}
	return (str);
}

unsigned int	process_x(va_list args)
{
	unsigned int	n;
	unsigned int	x;
	char			*x_s;
	char			*s;
	int				should_free;

	n = 0;
	x = va_arg(args, int);
	x_s = ft_itolowhex(x);
	if (!x_s)
		x_s = "(null)";
	should_free = (x != 0);
	s = x_s;
	while (*s)
	{
		write(1, s, 1);
		s++;
		n++;
	}
	if (should_free)
		free(x_s);
	return (n);
}