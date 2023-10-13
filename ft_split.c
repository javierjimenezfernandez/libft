/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:40:10 by javjimen          #+#    #+#             */
/*   Updated: 2023/10/06 13:15:48 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *s, char c)
{
	int		count;
	int		flag;

	count = 0;
	flag = 1;
	while (*s)
	{
		if (*s == c)
			flag = 1;
		else
		{
			if (flag)
			{
				count++;
				flag = 0;
			}
		}
		s++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	if (len)
		len++;
	return (len);
}

static char	**ft_memfail_free(char **s_array, int count)
{
	int	i;

	i = 0;
	while (count >= 0)
	{
		free(s_array[count]);
		count--;
	}
	free(s_array);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**s_array;
	int		word_count;
	int		i;

	i = 0;
	word_count = ft_count_words(s, c) + 1;
	s_array = (char **)malloc(word_count * sizeof (char *));
	if (!s_array)
		return (NULL);
	while (i + 1 < word_count)
	{
		s_array[i] = (char *)malloc(ft_wordlen(s, c) * sizeof (char));
		if (!s_array[i])
			return (ft_memfail_free(s_array, i));
		else
		{
			while (*s && *s == c)
				s++;
			ft_strlcpy(s_array[i], s, ft_wordlen(s, c));
			s += ft_wordlen(s, c);
		}
	i++;
	}
	s_array[i] = NULL;
	return (s_array);
}