/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:49:28 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/16 10:06:17 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

int				ft_printf(const char *str, ...);
int				process_p(va_list args);
unsigned int	process_u(va_list args);
unsigned int	process_x(va_list args);
unsigned int	process_xx(va_list args);
unsigned int	process_id(va_list args);
unsigned int	process_s(va_list args);
unsigned int	process_c(va_list args, char spec);

#endif // FT_PRINTF_H