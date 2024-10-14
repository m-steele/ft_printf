/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:41:17 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/14 16:49:42 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Just a place holder for the final product

#include <stdarg.h>
#include "libft.h"

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