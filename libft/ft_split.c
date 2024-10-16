/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekosnick <ekosnick@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 12:25:06 by ekosnick          #+#    #+#             */
/*   Updated: 2024/10/04 14:54:37 by ekosnick         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// use a delimiter char to break a string into chuncks
// ft__n_ofwords() to create 'n' to store the number of breaks (words) for
// ft_split(). ft_aryfree() to free memory. Recursive word writing did not 
// work  so ft_wwrite() to write each word, and ft_w_splt() to handle
//  the arrray of pointers
#include "libft.h"

static int	ft_n_ofwords(char const *s, char c, int n)
{
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			n++;
			while (*s && *s != c)
				s++;
		}
	}
	return (n);
}

static char	**aryfree(char **pnt, int i)
{
	while (i > 0)
	{
		i--;
		free(pnt[i]);
	}
	free(pnt);
	return (0);
}

static char	*ft_wwrite(char *word, char const *s, int i, int w_len)
{
	int	j;

	j = 0;
	while (w_len > 0)
	{
		word[j] = s[i - w_len];
		j++;
		w_len--;
	}
	word[j] = '\0';
	return (word);
}

static char	**ft_w_splt(char **s_pnt, const char *s, char delim, int nw)
{
	int	word;
	int	wlen;
	int	i;

	word = 0;
	wlen = 0;
	i = 0;
	while (word < nw)
	{
		while (s[i] && s[i] == delim)
			i++;
		while (s[i] && s[i] != delim)
		{
			i++;
			wlen++;
		}
		s_pnt[word] = (char *)malloc((wlen + 1) * sizeof(char));
		if (!s_pnt[word])
			return (aryfree(s_pnt, word));
		ft_wwrite(s_pnt[word], s, i, wlen);
		wlen = 0;
		word++;
	}
	s_pnt[word] = 0;
	return (s_pnt);
}

char	**ft_split(char const *s, char c)
{
	char	**ary4ary;
	int		n_ofwords;

	if (!s)
		return (NULL);
	n_ofwords = ft_n_ofwords(s, c, 0);
	ary4ary = (char **)malloc((n_ofwords + 1) * sizeof(char *));
	if (!ary4ary)
		return (NULL);
	return (ft_w_splt(ary4ary, s, c, n_ofwords));
}

// Copy eac word, recursively
// static char	**ft_write_words(char **words, char const *s, char c, int i)
// {
// 	char	*catch;
// 	int		len;

// 	len = 0;
// 	while (*s == c)
// 		s++;
// 	if (*s == '\0')
// 	{
// 		words[i] = NULL;
// 		return (words);
// 	}
// 	catch = (char *)s;
// 	while (*s != c && *s != '\0')
// 	{
// 		len++;
// 		s++;
// 	}
// 	words[i] = (char *)malloc((len + 1) * sizeof(char));
// 	if (!words[i])
// 		return (aryfree(words, i));
// 	ft_strlcpy(words[i], catch, len + 1);
// 	return (ft_write_words(words, s, c, i + 1));
// }