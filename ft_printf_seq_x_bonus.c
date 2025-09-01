/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_seq_x_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuqare <mabuqare@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 14:54:23 by mabuqare          #+#    #+#             */
/*   Updated: 2025/08/30 14:54:24 by mabuqare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	calculate_zeros_and_spaces(t_formatting_info *f_info,
		int *num_of_zeros, int *num_of_spaces, int *num_len)
{
	*num_of_spaces = 0;
	*num_of_zeros = 0;
	if (f_info->precision > 0 && f_info->precision > *num_len)
	{
		*num_of_zeros += f_info->precision - *num_len;
		*num_len += *num_of_zeros;
	}
	if (f_info->hex_prefix)
		*num_len += 2;
	if (f_info->padding_char == '0' && f_info->width > *num_len)
		*num_of_zeros += f_info->width - *num_len;
	else if (f_info->padding_char == ' ' && f_info->width > *num_len)
		*num_of_spaces += f_info->width - *num_len;
}

static char	*ft_parse_num_input(t_formatting_info *f_info, va_list *args,
		int *num_len)
{
	char			*num_str;
	unsigned int	input_num;

	num_str = NULL;
	input_num = va_arg(*args, unsigned int);
	if (!input_num && f_info->precision == -1)
	{
		f_info->hex_prefix = 0;
		num_str = ft_strdup("0");
	}
	else if (!input_num && f_info->precision == 0)
	{
		num_str = ft_strdup("");
		f_info->hex_prefix = 0;
	}
	else if (f_info->specifier == 'x')
		num_str = ft_long_itoa_base(input_num, 16, "0123456789abcdef");
	else if (f_info->specifier == 'X')
		num_str = ft_long_itoa_base(input_num, 16, "0123456789ABCDEF");
	*num_len += (int)ft_strlen(num_str);
	return (num_str);
}

static void	ft_print_prefix(t_formatting_info *f_info, int *total)
{
	ft_print_c('0', total);
	ft_print_c(f_info->specifier, total);
}

static void	ft_print_seq(t_formatting_info *f_info, int padding[2],
		char *num_str, int *total)
{
	int	num_of_zeros;
	int	num_of_spaces;

	num_of_zeros = padding[0];
	num_of_spaces = padding[1];
	if (f_info->justify_left)
	{
		if (f_info->hex_prefix)
			ft_print_prefix(f_info, total);
		while (num_of_zeros--)
			ft_print_c('0', total);
		ft_print_s(num_str, total);
		while (num_of_spaces--)
			ft_print_c(' ', total);
	}
	else
	{
		while (num_of_spaces--)
			ft_print_c(' ', total);
		if (f_info->hex_prefix)
			ft_print_prefix(f_info, total);
		while (num_of_zeros--)
			ft_print_c('0', total);
		ft_print_s(num_str, total);
	}
}

void	ft_print_x_seq(t_formatting_info *f_info, va_list *args, int *total)
{
	char	*num_str;
	int		num_len;
	int		num_of_zeros;
	int		num_of_spaces;
	int		padding[2];

	num_len = 0;
	num_str = ft_parse_num_input(f_info, args, &num_len);
	calculate_zeros_and_spaces(f_info, &num_of_zeros, &num_of_spaces, &num_len);
	padding[0] = num_of_zeros;
	padding[1] = num_of_spaces;
	ft_print_seq(f_info, padding, num_str, total);
	free(num_str);
}
