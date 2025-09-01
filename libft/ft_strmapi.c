/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuqare <mabuqare@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:51:35 by mabuqare          #+#    #+#             */
/*   Updated: 2025/08/15 18:50:42 by mabuqare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*s_modified;

	if (!s || !f)
		return (NULL);
	s_modified = malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (!s_modified)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s_modified[i] = f(i, s[i]);
		i++;
	}
	s_modified[i] = '\0';
	return (s_modified);
}
