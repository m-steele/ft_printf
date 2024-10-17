/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 10:17:53 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/17 16:54:08 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_ptoa(unsigned long pt)
{
	char			*str;
	char			*base;
	unsigned long	p;
	int				len;

	base = "0123456789abcdef";
	p = pt;
	len = 0;
	while (p)
	{
		p /= 16;
		len++;
	}
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

int	process_p(va_list args)
{
	int		n;
	void	*p;
	char	*p_s;
	char	*s;

	n = 0;
	p = va_arg(args, void *);
	p_s = ft_ptoa((unsigned long)p);
	if (!p_s)
		p_s = "(null)";
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
