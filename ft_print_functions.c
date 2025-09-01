/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuqare  <mabuqare@student.42amman.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 23:26:33 by mabuqare          #+#    #+#             */
/*   Updated: 2025/09/01 11:17:02 by mabuqare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(char c, int *total)
{
	ft_putchar_fd(c, 1);
	*total += 1;
}

void	ft_print_s(char *str, int *total)
{
	if (!str)
		ft_print_s("(null)", total);
	else
	{
		ft_putstr_fd(str, 1);
		*total += ft_strlen(str);
	}
}

void	ft_print_i(int num, int *total)
{
	int	len;

	len = 1;
	ft_putnbr_fd(num, 1);
	while (num / 10)
	{
		num /= 10;
		len++;
	}
	if (num < 0)
		len++;
	*total += len;
}

void	ft_print_u(unsigned int num, int *total)
{
	int	len;

	len = 1;
	ft_putunbr_fd(num, 1);
	while (num / 10)
	{
		num /= 10;
		len++;
	}
	*total += len;
}

void	ft_print_specifier(char c, va_list *args, int *total)
{
	if (c == 'c')
		ft_print_c(va_arg(*args, int), total);
	if (c == 's')
		ft_print_s(va_arg(*args, char *), total);
	if (c == 'd' || c == 'i')
		ft_print_i(va_arg(*args, int), total);
	if (c == 'u')
		ft_print_u(va_arg(*args, unsigned int), total);
	if (c == 'p')
		ft_print_p(va_arg(*args, void *), total);
	if (c == 'x' || c == 'X')
		ft_print_x(va_arg(*args, unsigned int), 0, c, total);
	if (c == '%')
		ft_print_c('%', total);
}
