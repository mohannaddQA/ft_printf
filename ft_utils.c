/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuqare  <mabuqare@student.42amman.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 22:51:21 by mabuqare          #+#    #+#             */
/*   Updated: 2025/08/29 11:54:40 by mabuqare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_specifier(char specifier)
{
	return (specifier == 'c' || specifier == 's' || specifier == 'p'
		|| specifier == 'd' || specifier == 'i' || specifier == 'u'
		|| specifier == 'x' || specifier == 'X' || specifier == '%');
}

int	is_flag(char c)
{
	return (c == '-' || c == '0' || c == ' ' || c == '+' || c == '#');
}

int	is_valid_width(char *str, int *i)
{
	int	asterisk;
	int	digits;

	asterisk = 0;
	digits = 0;
	while (str[*i] && ((ft_isdigit(str[*i])) || str[*i] == '*'))
	{
		if (str[*i] == '*')
			asterisk++;
		if ((ft_isdigit(str[(*i)])))
			digits++;
		if ((digits && asterisk) || asterisk > 1)
			return (0);
		(*i)++;
	}
	return (1);
}

int	is_valid_precision(char *str, int *i)
{
	int	asterisk;
	int	digits;

	asterisk = 0;
	digits = 0;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] && ((ft_isdigit(str[*i])) || str[*i] == '*'))
		{
			if (str[*i] == '*')
				asterisk++;
			if ((ft_isdigit(str[(*i)])))
				digits++;
			if ((digits && asterisk) || asterisk > 1)
				return (0);
			(*i)++;
		}
	}
	return (1);
}
