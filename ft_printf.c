/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:41:17 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/09 14:26:31 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int type_ck(const char *type, va_list args)
{
	// char	c;
	char	*s;
	// // int		d;
	// int		n;

	// n = 0;
	// c = va_arg(args, int);
	// s = va_arg(args, char *);
	// d = va_arg(args, int);

	// if (type = "c")
	// {
	// 	write(1, &c, 1);
	// 	n++;
	// }
/*	else*/ if (type == 's')
	{
		s = va_arg(args, char *);
		while (*s)
		{
			write(1, s, 1);
			s++;
			type++;
		}
	}
	// else if (type == 'd')
	// {
		
	// 	while (ft_itoa(d));
	// 	write(1, ft_itoa(d), 1);
		
	// }
	else if (*type == '\0')
		return (type);
(type_ck(type, args));
}

int ft_printf(const char *type, ...)
{
	va_list args;
	int n;

	n = 0;
	if (!type)
		return (0);
	va_start(args, type);
	// int ret = vprintf(type, args);
	while(*type != '%')
	{
		write(1, type, 1);
		type++;
		n++;
	}
		if(*type == '%')
		{
			type++;
			n +=type_ck(type, args);	
		}
	va_end(args);
	return (n);
}

#include <stdio.h>
int main()
{
	char s1[] ="as fat as";
	// int num = 3;

// %d\n

//  printf("\033[1;36mREMEMBER COLOR\033[0m\n")
	ft_printf("You are\n%s\npigs\n\n", s1 /*, num*/);
	printf("\033[1;91mYou are\n%s\npigs\n\n\033[0m]", s1 /*, num*/);
	return(0);
}