/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   working_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:41:17 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/14 17:09:37 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static	unsigned int	process_x(va_list args)
{
	unsigned int	n;
	unsigned int	x;
	char			*x_s;
	char			*s;

	n = 0;
	x = va_arg(args, int);
	x_s = ft_itolowhex(x);
	if (!x_s)
		x_s = "(NULL)";
	s = x_s;
	while (*s)
	{
		write(1, s, 1);
		s++;
		n++;
	}
	free(x_s);
	return (n);
}

static	unsigned int	process_xx(va_list args)
{
	unsigned int	n;
	unsigned int	xx;
	char			*xx_s;
	char			*s;

	n = 0;
	xx = va_arg(args, int);
	xx_s = ft_itoupperhex(xx);
	if (!xx_s)
		xx_s = "(NULL)";
	s = xx_s;
	while (*s)
	{
		write(1, s, 1);
		s++;
		n++;
	}
	free(xx_s);
	return (n);
}

static	unsigned int	process_u(va_list args)
{
	unsigned int	n;
	unsigned int	u;
	char			*u_s;
	char			*s;

	n = 0;
	u = va_arg(args, int);
	u_s = ft_utoa(u);
	if (!u_s)
		u_s = "(NULL)";
	s = u_s;
	while (*s)
	{
		write(1, s, 1);
		s++;
		n++;
	}
	free(u_s);
	return (n);
}

static	int	process_p(va_list args)
{
	int		n;
	void	*p;
	char	*p_s;
	char	*s;

	n = 0;
	p = va_arg(args, void *);
	p_s = ft_ptoa((unsigned long)p);
	if (!p_s)
		p_s = "(NULL)";
	s = p_s;
	write(1, "0x", 2);
	n += 2;
	while (*s)
	{
		write(1, s, 1);
		s++;
		n++;
	}
	free(p_s);
	return (n);
}

static	int process_id(va_list args)
{
	int			n;
	int			i;
	char		*i_s;
	char		*s;

	n = 0;
	i = va_arg(args, int);
	i_s = ft_itoa(i);
	if (!i_s)
		i_s = "(NULL)";
	s = i_s;
	while (*s)
	{
		write(1, s, 1);
		s++;
		n++;
	}
	free(i_s);
	return (n);
}

static int process_s(va_list args)
{
	int		n;
	char	*s;

	n = 0;
	s = va_arg(args, char *);
	if (!s)
		s = "(NULL)";
	while (*s)
	{
		write(1, s, 1);
		s++;
		n++;
	}
	return (n);
}

static int process_c(va_list args, char spec)
	{
		char	c;
		
		if (spec == 'c')
			c = va_arg(args, int);
		else
			c = '%';
		write(1, &c, 1);
		return (1);
	}

int	type_ck(const char *str, va_list args)
{
	int		n;

	n = 0;
	if (*str == 's')
		n += process_s(args);
	else if (*str == 'i' || *str == 'd')
		n += process_id(args);
	else if (*str == 'c' || *str == '%')
		n += process_c(args, *str);
	else if (*str == 'p')
		n += process_p(args);
	else if (*str == 'u')
		n += process_u(args);
	else if (*str == 'x')
		n += process_x(args);
	else if (*str == 'X')
		n += process_xx(args);
	else
		return (0);
	return (n);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		n;

	n = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == '%')
			{
				write(1, "%", 1);
				n++;
			}
			else if (*str)
				n +=type_ck (str, args);
		}
		else
		{
			write(1, str, 1);
			n++;
		}
		str++;
	}
	va_end(args);
	return (n);
}

#include <stdio.h>
int main()
{
	char s0[] = "Hey";
	char s1 = 'Y';
	int num = -300;
	int perc = 98;
	char *ptr = "zxcv";
	unsigned int usint = 4294967295;
	unsigned int hexlow = 0;
	unsigned int hexupp = 48879;
	const char	*test_str = "%s\n%cou\nint: %i %%\ndecimal: %d @ %p\nunsigned: %u\nHex Low: %x\nHex UPP: %X\n\n";

	printf("\033[1;91m");
	int printf_count = printf(test_str, s0, s1, num, perc, ptr, usint, hexlow, hexupp);
	printf("printf returned using printf: %d\n", printf_count);
	ft_printf("printf returned using ft_printf: %d\n", printf_count);
	printf("\033[0m\n\n");

	ft_printf("\033[1;33m");
	int ft_printf_count = ft_printf(test_str, s0, s1, num, perc, ptr, usint, hexlow, hexupp);
	printf("ft_printf returned using printf: %d\n", ft_printf_count);
	ft_printf("ft_printf returned using ft_printf: %d\n", ft_printf_count);
	ft_printf("\033[0m");
	return(0);
}

//  printf("\033[1;36mREMEMBER COLOR\033[0m\n")
