/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_id.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 09:56:08 by peatjohnsto       #+#    #+#             */
/*   Updated: 2024/10/17 16:54:04 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	process_id(va_list args)
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
