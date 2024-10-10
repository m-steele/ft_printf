/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:41:17 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/10 11:36:26 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

int type_ck(const char *type, va_list args)
{
	char	c;
	char	*s;
	char	*d_s;
	int		d;
	int		n;

	n = 0;
	if (*type == 's')
	{
		s = va_arg(args, char *);
		if (!s)
			s = "(NULL)";
		while (*s)
		{
			write(1, s, 1);
			s++;
			n++;
		}
	}
	else if (*type == 'c')
	{
		c = va_arg(args, int);
		write(1, &c, 1);
		n++;
	}
	else if (*type == 'd')
	{
		d = va_arg(args, int);
		d_s = ft_itoa(d);
		if (!d_s)
			d_s = "(NULL)";
		while (*d_s)
		{
			write(1, d_s, 1);
			d_s++;
			n++;
		}
		free(d_s - n);
	}
	else
		return (0);
	return (n);
}

int ft_printf(const char *type, ...)
{
	va_list args;
	int n;

	n = 0;
	if (!type)
		return (0);
	va_start(args, type);
	while(*type)
	{
		if(*type == '%')
		{
			type++;
			if (*type)
				n +=type_ck(type, args);	
		}
		else
		{
			write(1, type, 1);
			n++;
		}
		type++;
	}
	va_end(args);
	return (n);
}

#include <stdio.h>
int main()
{
	char s0[] = "Hey Chump";
	char s1 = 'Y';
	char s2[] ="as fat as";
	int num = 3;
	printf("\033[1;91m%s\n%cou are\n%s\n%d\npigs\n\n\033[0m", s0, s1, s2, num);
	ft_printf("\033[1;33m%s\n%cou are\n%s\n%d\npigs\n\n\033[0m", s0, s1, s2, num);
	return(0);
}
//  printf("\033[1;36mREMEMBER COLOR\033[0m\n")
