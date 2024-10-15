/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:49:28 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/15 13:28:18 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"

int				ft_printf(const char *str, ...);
int				process_p(va_list args);
unsigned int	process_u(va_list args);
unsigned int	process_x(va_list args);
unsigned int	process_xx(va_list args);

#endif // LIBFTPRINTF_H