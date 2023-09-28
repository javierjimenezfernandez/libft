/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:51:53 by javjimen          #+#    #+#             */
/*   Updated: 2023/09/21 15:19:13 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int					i;
	unsigned char		*aux_dst;
	unsigned const char	*aux_src;

	i = 0;
	aux_dst = dst;
	aux_src = src;
	if (!(dst == NULL && src == NULL))
	{
		if (src < dst && dst <= (src + len))
		{
			while (len-- > 0)
				aux_dst[len] = aux_src[len];
		}
		else
		{
			while (len-- > 0)
			{
				aux_dst[i] = aux_src[i];
				i++;
			}
		}	
	}
	return (dst);
}