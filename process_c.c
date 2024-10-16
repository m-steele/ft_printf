/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 10:00:48 by peatjohnsto       #+#    #+#             */
/*   Updated: 2024/10/16 10:08:21 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

unsigned int	process_c(va_list args, char spec)
{
	char	c;

	if (spec == 'c')
		c = va_arg(args, int);
	else
		c = '%';
	write(1, &c, 1);
	return (1);
}
