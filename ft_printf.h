/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peatjohnston <peatjohnston@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:49:28 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/17 17:11:43 by peatjohnsto      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <limits.h>
# include <unistd.h>
# include <stdint.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include "ft_printf.h"

int				ft_printf(const char *str, ...);
int				process_p(va_list args);
unsigned int	process_u(va_list args);
unsigned int	process_x(va_list args);
unsigned int	process_xx(va_list args);
unsigned int	process_id(va_list args);
unsigned int	process_s(va_list args);
unsigned int	process_c(va_list args, char spec);

char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

#endif // FT_PRINTF_H