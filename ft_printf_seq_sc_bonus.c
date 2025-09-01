/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_seq_sc_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuqare <mabuqare@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 01:58:18 by mabuqare          #+#    #+#             */
/*   Updated: 2025/08/30 20:14:57 by mabuqare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c_seq(t_formatting_info *f_info, va_list *args, int *total)
{
	char	input_char;

	input_char = va_arg(*args, int);
	if (f_info->width <= 1)
		return (ft_print_c(input_char, total));
	else if (f_info->justify_left)
	{
		ft_print_c(input_char, total);
		while (f_info->width-- - 1 > 0)
			ft_print_c(f_info->padding_char, total);
	}
	else
	{
		while (f_info->width-- - 1 > 0)
			ft_print_c(f_info->padding_char, total);
		ft_print_c(input_char, total);
	}
}

void	handle_null_str(t_formatting_info *f_info, char **input_str)
{
	*input_str = ft_strdup("(null)");
	if (f_info->precision >= 0 && f_info->precision <= 5)
		f_info->precision = 0;
}

void	ft_print_s_seq(t_formatting_info *f_info, va_list *args, int *total)
{
	char	*input_str;
	int		input_len;
	char	*str;

	input_str = va_arg(*args, char *);
	if (!input_str)
		handle_null_str(f_info, &input_str);
	else
		input_str = ft_strdup(input_str);
	if (!input_str)
		return ;
	if (f_info->precision <= (int)ft_strlen(input_str)
		&& f_info->precision >= 0)
		input_str[f_info->precision] = '\0';
	input_len = (int)ft_strlen(input_str);
	if (input_len > f_info->width)
		f_info->width = input_len;
	str = ft_calloc(f_info->width + 1, sizeof(char));
	if (!str)
		return ;
	copy_pad_str(f_info, str, input_str);
	ft_print_s(str, total);
	free(input_str);
	free(str);
}
