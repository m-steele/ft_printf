/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_working_printf.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:41:17 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/11 11:51:02 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

static int	process_s(char	*s)
{
	int n = 0;
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
static	int process_i(int i)
{
	int			n;
	static char	*i_s;
	char		*s;

	n = 0;
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

int	type_ck(const char *type, va_list args)
{
	char	c;
	char	*s;
	int		i;
	int		n;

	if (*type == 's')
	{
		s = va_arg(args, char *);
		n +=process_s(s);
	}
	else if (*type == 'i')
	{
		i = va_arg(args, int);
		n +=process_i(i);
	}
	else if (*type == 'c' || *type == 37)
	{
		if (*type == 'c')
			c = va_arg(args, int);
		else
			c = '%';
		write(1, &c, 1);
		n++;
	}
	else
		return (0);
	return (n);
}

int	ft_printf(const char *type, ...)
{
	va_list	args;
	int		n;

	n = 0;
	if (!type)
		return (0);
	va_start(args, type);
	while (*type)
	{
		if (*type == '%')
		{
			type++;
			if (*type)
				n +=type_ck (type, args);
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
	char s0[] = "Hey";
	char s1 = 'Y';
	char s2[] ="are";
	int num = -300;
	printf("\033[1;91m%s\n%cou %s\n%i %% + 10\npigs\n\n\033[0m", s0, s1, s2, num);
	ft_printf("\033[1;33m%s\n%cou %s\n%i %% + 10\npigs\n\n\033[0m", s0, s1, s2, num);
	return(0);
}
//  printf("\033[1;36mREMEMBER COLOR\033[0m\n")
