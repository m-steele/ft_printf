/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:52:21 by peatjohnsto       #+#    #+#             */
/*   Updated: 2024/10/14 11:15:09 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
// used to convert a pointer to ascii; Note that 0x needs
// to be added to the begining
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