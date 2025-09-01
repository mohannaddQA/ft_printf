/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuqare <mabuqare@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:51:48 by mabuqare          #+#    #+#             */
/*   Updated: 2025/08/15 18:50:46 by mabuqare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_ascii_array(int *arr, char const *set)
{
	ft_bzero(arr, 128 * sizeof(int));
	while (*set)
	{
		if (!arr[(int)*set])
			arr[(int)*set] = 1;
		set++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			ascii[128];
	int			len;
	char		*trimmed_str;

	if (!s1 || !set)
		return (NULL);
	fill_ascii_array(ascii, set);
	while (ascii[(int)*s1])
		s1++;
	if (!*s1)
		return (ft_strdup(""));
	len = ft_strlen(s1);
	while (ascii[(int)s1[len - 1]])
		len--;
	trimmed_str = malloc(sizeof(char) * (len + 1));
	if (!trimmed_str)
		return (NULL);
	ft_strlcpy(trimmed_str, s1, len + 1);
	return (trimmed_str);
}
