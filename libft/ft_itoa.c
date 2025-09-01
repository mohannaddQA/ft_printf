/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuqare <mabuqare@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 23:49:52 by mabuqare          #+#    #+#             */
/*   Updated: 2025/08/15 18:50:08 by mabuqare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int				len;

	len = 1;
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	if (n < 0)
		return (len + 1);
	return (len);
}

char	*ft_itoa(int n)
{
	int				len;
	char			*itoa;
	long			long_n;

	long_n = (long)n;
	len = num_len(n);
	itoa = malloc(sizeof(char) * (len + 1));
	if (!itoa)
		return (NULL);
	itoa[len--] = '\0';
	if (long_n < 0)
	{
		itoa[0] = '-';
		long_n *= -1;
	}
	while (len >= 0)
	{
		if (itoa[len] == '-')
			break ;
		itoa[len--] = (long_n % 10) + '0';
		long_n /= 10;
	}
	return (itoa);
}
