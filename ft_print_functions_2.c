/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_functions_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuqare <mabuqare@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 11:34:47 by mabuqare          #+#    #+#             */
/*   Updated: 2025/08/31 12:43:28 by mabuqare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(void *ptr, int has_prefix, char type, char *digits)
{
	if (!has_prefix)
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd(type, 1);
	}
	if ((unsigned long long)ptr > 15)
		ft_putptr(((void *)((unsigned long long)ptr / 16)), 1, type, digits);
	ft_putchar_fd(digits[(unsigned long long)ptr % 16], 1);
}

void	ft_puthex(unsigned int num, int has_prefix, char prefix_char)
{
	char	*digits;

	digits = NULL;
	if (prefix_char == 'x')
		digits = "0123456789abcdef";
	else if (prefix_char == 'X')
		digits = "0123456789ABCDEF";
	if (has_prefix)
	{
		ft_putchar_fd('0', 1);
		ft_putchar_fd(prefix_char, 1);
	}
	if (num > 15)
		ft_puthex((num / 16), 0, prefix_char);
	ft_putchar_fd(digits[num % 16], 1);
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void	ft_print_p(void *ptr, int *total)
{
	int					len;
	unsigned long long	ptr_hex;

	if (!ptr)
		ft_print_s("(nil)", total);
	else
	{
		ft_putptr(ptr, 0, 'x', "0123456789abcdef");
		ptr_hex = (unsigned long long)ptr;
		len = 3;
		while (ptr_hex / 16)
		{
			ptr_hex /= 16;
			len++;
		}
		*total += len;
	}
}

void	ft_print_x(unsigned int num, int has_prefix, char prefix_char,
		int *total)
{
	int	len;

	ft_puthex(num, has_prefix, prefix_char);
	if (has_prefix)
		len = 3;
	else
		len = 1;
	while (num / 16)
	{
		num /= 16;
		len++;
	}
	*total += len;
}
