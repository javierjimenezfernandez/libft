/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javjimen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 17:50:58 by javjimen          #+#    #+#             */
/*   Updated: 2023/09/22 13:29:55 by javjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ret;

	ret = ft_strlen(src);
	if (dstsize >= ft_strlen(dst))
		ret += ft_strlen(dst);
	else if (dstsize < ft_strlen(src) || dstsize < ft_strlen(dst))
		ret += dstsize;
	if (dstsize > ft_strlen(dst))
		ft_strlcpy(dst + ft_strlen(dst), src, dstsize - ft_strlen(dst));
	return (ret);
}
