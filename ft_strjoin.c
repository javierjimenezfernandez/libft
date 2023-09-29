/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:15:31 by javjimen          #+#    #+#             */
/*   Updated: 2023/09/29 16:23:32 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoin;
	size_t	size;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	strjoin = (char *)malloc(size * sizeof(char));
	if (strjoin)
	{
		while (s1[i] != '\0')
		{
			strjoin[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			strjoin[i] = s2[j];
			i++;
			j++;
		}
		strjoin[i] = '\0';
	}
	return (strjoin);
}
