/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   working_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:41:17 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/15 10:21:53 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

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
