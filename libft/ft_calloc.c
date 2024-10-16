/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 09:46:11 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/04 14:47:43 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sets all the allocated bytes to 0
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*pnt;
	size_t			i;

	i = 0;
	if (nmemb && (nmemb * size) / nmemb != size)
		return (NULL);
	pnt = (void *)malloc(nmemb * size);
	if (!pnt)
		return (NULL);
	while (i < nmemb * size)
		pnt[i++] = 0;
	return (pnt);
}
