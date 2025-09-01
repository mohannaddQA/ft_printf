/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuqare <mabuqare@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 19:26:23 by mabuqare          #+#    #+#             */
/*   Updated: 2025/08/15 18:50:40 by mabuqare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	while (*src && (dstsize-- > 1))
		*dst++ = *src++;
	*dst = '\0';
	return (srclen);
}

/*
Takes the total buffer size: 
Buffer = 0 --> nothing to copy
Buffer > 0 --> Copy src till it (or buffer) finishes
return the string we tried to copy (srclen) 
*/