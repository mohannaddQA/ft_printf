/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuqare <mabuqare@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:51:45 by mabuqare          #+#    #+#             */
/*   Updated: 2025/08/15 18:50:45 by mabuqare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*last;
	unsigned char	ch;

	ch = (unsigned char)c;
	last = NULL;
	while (*s != '\0')
	{
		if (*s == ch)
			last = (char *)s;
		s++;
	}
	if (*s == ch)
		return ((char *)s);
	return (last);
}
