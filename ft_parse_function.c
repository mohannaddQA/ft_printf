/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuqare  <mabuqare@student.42amman.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:17:30 by mabuqare          #+#    #+#             */
/*   Updated: 2025/08/29 01:50:55 by mabuqare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_sequence(char *str, va_list *args, int *pos, int *total)
{
	int	i;

	i = 1;
	if (is_specifier(str[i]))
	{
		ft_print_specifier(str[i], args, total);
		*pos += i;
	}
	else
		ft_print_c('%', total);
}
