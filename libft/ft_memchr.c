/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuqare <mabuqare@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:50:29 by mabuqare          #+#    #+#             */
/*   Updated: 2025/08/15 18:50:20 by mabuqare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_cpy;
	unsigned char		c_cpy;

	s_cpy = (const unsigned char *)s;
	c_cpy = c;
	while (n--)
	{
		if (*s_cpy++ == c_cpy)
			return ((void *)(s_cpy - 1));
	}
	return (NULL);
}
