/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_seq_p_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuqare  <mabuqare@student.42amman.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:19:25 by mabuqare          #+#    #+#             */
/*   Updated: 2025/08/30 11:46:00 by mabuqare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	calculate_zeros_and_spaces(t_formatting_info *f_info,
		int padding[2], char *ptr_str, int *num_len)
{
	padding[0] = 0;
	padding[1] = 0;
	if (f_info->precision > *num_len && ft_strncmp(ptr_str, "(nil)", 5) != 0)
	{
		padding[0] += f_info->precision - *num_len;
		*num_len += padding[0];
	}
	if (ft_strncmp(ptr_str, "(nil)", 5) != 0)
		*num_len += 2;
	if (f_info->sign_char && ft_strncmp(ptr_str, "(nil)", 5) != 0)
		*num_len += 1;
	if (f_info->padding_char == '0' && f_info->width > *num_len)
		padding[0] += f_info->width - *num_len;
	else if (f_info->padding_char == ' ' && f_info->width > *num_len)
		padding[1] += f_info->width - *num_len;
}

static char	*ft_parse_pointer_input(t_formatting_info *f_info, va_list *args,
		int *num_len)
{
	void	*input_ptr;
	char	*num_str;

	input_ptr = va_arg(*args, void *);
	if (!input_ptr)
	{
		num_str = ft_strdup("(nil)");
		*num_len += (int)ft_strlen(num_str);
		f_info->padding_char = ' ';
		f_info->precision = *num_len;
		f_info->sign_char = '\0';
		f_info->hex_prefix = 0;
		return (num_str);
	}
	num_str = ft_ptoa(input_ptr);
	*num_len += (int)ft_strlen(num_str);
	return (num_str);
}

static void	ft_print_prefix(int *total)
{
	ft_print_c('0', total);
	ft_print_c('x', total);
}

static void	ft_print_seq(t_formatting_info *f_info, int padding[2],
		char *ptr_str, int *total)
{
	if (f_info->justify_left)
	{
		if (f_info->sign_char && ft_strncmp(ptr_str, "(nil)", 5) != 0)
			ft_print_c(f_info->sign_char, total);
		if (ft_strncmp(ptr_str, "(nil)", 5) != 0)
			ft_print_prefix(total);
		while (padding[0]--)
			ft_print_c('0', total);
		ft_print_s(ptr_str, total);
		while (padding[1]--)
			ft_print_c(' ', total);
	}
	else
	{
		while (padding[1]--)
			ft_print_c(' ', total);
		if (f_info->sign_char && ft_strncmp(ptr_str, "(nil)", 5) != 0)
			ft_print_c(f_info->sign_char, total);
		if (ft_strncmp(ptr_str, "(nil)", 5) != 0)
			ft_print_prefix(total);
		while (padding[0]--)
			ft_print_c('0', total);
		ft_print_s(ptr_str, total);
	}
}

void	ft_print_p_seq(t_formatting_info *f_info, va_list *args, int *total)
{
	char	*ptr_str;
	int		padding[2];
	int		num_len;

	num_len = 0;
	ptr_str = ft_parse_pointer_input(f_info, args, &num_len);
	calculate_zeros_and_spaces(f_info, padding, ptr_str, &num_len);
	ft_print_seq(f_info, padding, ptr_str, total);
	free(ptr_str);
}
