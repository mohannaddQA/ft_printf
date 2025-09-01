/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuqare <mabuqare@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:48:35 by mabuqare          #+#    #+#             */
/*   Updated: 2025/08/15 18:52:00 by mabuqare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_new;
	unsigned char	*src_new;

	dest_new = (unsigned char *)dest;
	src_new = (unsigned char *)src;
	if (dest == src)
		return (dest);
	if (dest_new < src_new)
	{
		while (n--)
			*(dest_new++) = *(src_new++);
	}
	else
	{
		while (n--)
			*(dest_new + n) = *(src_new + n);
	}
	return (dest);
}
