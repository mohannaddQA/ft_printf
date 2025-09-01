/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuqare <mabuqare@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 01:36:50 by mabuqare          #+#    #+#             */
/*   Updated: 2025/08/15 18:50:39 by mabuqare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	finallen;

	i = 0;
	if (size == 0 || size <= ft_strlen((const char *)dst))
		return (ft_strlen((const char *)src) + size);
	if (size > ft_strlen((const char *)dst))
		finallen = ft_strlen((const char *)src) + ft_strlen((const char *)dst);
	while (dst[i])
		i++;
	while (*src && i < size - 1)
	{
		dst[i++] = *src;
		src++;
	}
	dst[i] = '\0';
	return (finallen);
}

/*
Takes the total buffer size: 
Buffer = 0 --> nothing to copy
Buffer = destlen --> nothing to copy
Buffer < destlen --> nothing to copy
return strlen + buffer size (the string we tried to create)
Buffer > destlen --> somthing to copy
return destlen + srclen (the string we tried to create)
*/