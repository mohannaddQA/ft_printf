/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuqare <mabuqare@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:51:52 by mabuqare          #+#    #+#             */
/*   Updated: 2025/08/15 18:50:48 by mabuqare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	actual_len;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	actual_len = ft_strlen(s) - start;
	if (len < actual_len)
		actual_len = len;
	sub_str = (char *)malloc((sizeof(char)) * (actual_len + 1));
	if (!sub_str)
		return (NULL);
	ft_strlcpy(sub_str, (char *)&s[start], actual_len + 1);
	return (sub_str);
}
