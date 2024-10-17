/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:51:25 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/17 16:47:50 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoupperhex(unsigned long num)
{
	char			*str;
	char			*hex;
	unsigned long	x;
	int				len;

	hex = "0123456789ABCDEF";
	x = num;
	len = 0;
	while (x)
	{
		x /= 16;
		len++;
	}
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

unsigned int	process_xx(va_list args)
{
	unsigned int	n;
	unsigned int	xx;
	char			*xx_s;
	char			*s;

	n = 0;
	xx = va_arg(args, int);
	// if (xx == 0)
	// 	xx_s ="0";
	// else
		xx_s = ft_itoupperhex(xx);
	if (!xx_s)
		xx_s = "(null)";
	s = xx_s;
// printf("HERE %s\n", s);
	while (*s)
	{
		write(1, s, 1);
		s++;
		n++;
	}
	free(xx_s);
	return (n);
}
