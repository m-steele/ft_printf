/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   working_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:41:17 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/14 11:11:25 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

char *ft_ptoa(unsigned long pt)
{
	char			*str;
	char			*base;
	unsigned long	p;
	int				len;

	base = "0123456789abcdef";
	p = pt;
	len = 1;
	while (p /= 16)
		len++;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len] = '\0';
	while (len--)
	{
		str[len] = base[pt % 16];
		pt /= 16;
	}
	return (str);
}

static	int process_p(va_list args)
{
	int		n;
	void	*p;
	char	*ps;
	char	*s;

	n = 0;
	p = va_arg(args, void *);
	ps = ft_ptoa((unsigned long)p);
	if (!ps)
		ps = "(NULL)";
	s = ps;
	write(1, "0x", 2);
	n += 2;
	while (*s)
	{
		write(1, s, 1);
		s++;
		n++;
	}
	free(ps);
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
	char s2[] ="are";
	int num = -300;
	int perc = 98;
	char	*ptr = "74";
	const char	*test_str = "%s\n%cou %s\n%i %% + %d @ %p\n\n";

	printf("\033[1;91m");
	int printf_count = printf(test_str, s0, s1, s2, num, perc, ptr);
	printf("printf returned using printf: %d\n", printf_count);
	ft_printf("printf returned using ft_printf: %d\n", printf_count);
	printf("\033[0m\n\n");

	ft_printf("\033[1;33m");
	int ft_printf_count = ft_printf(test_str, s0, s1, s2, num, perc, ptr);
    // int ft_printf_count = ft_printf("%s\n%cou %s\n%i %% + 10\npigs\n\n", s0, s1, s2, num, perc);
	printf("ft_printf returned using printf: %d\n", ft_printf_count);
	ft_printf("ft_printf returned using ft_printf: %d\n", ft_printf_count);
	ft_printf("\033[0m");
	return(0);
}

//  printf("\033[1;36mREMEMBER COLOR\033[0m\n")
