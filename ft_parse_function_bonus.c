/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_function_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuqare  <mabuqare@student.42amman.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 10:17:30 by mabuqare          #+#    #+#             */
/*   Updated: 2025/09/01 11:16:27 by mabuqare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*extract_valid_sequence(char *str, int *pos)
{
	int	i;

	i = 0;
	while (is_flag(str[i]))
		i++;
	if (!(is_valid_width(str, &i) && is_valid_precision(str, &i)))
		return (NULL);
	if (is_specifier(str[i]))
	{
		*pos += ++i;
		return (ft_substr(str, 0, i));
	}
	return (NULL);
}

static void	handle_width_presision_input(t_formatting_info *f_info,
		va_list *args)
{
	if (f_info->width == -1)
	{
		f_info->width = va_arg(*args, int);
		if (f_info->width < 0)
		{
			f_info->justify_left = 1;
			f_info->padding_char = ' ';
			f_info->width *= -1;
		}
	}
	if (f_info->precision == -2)
		f_info->precision = va_arg(*args, int);
}

void	ft_print_sequence(t_formatting_info *f_info, va_list *args, int *total)
{
	handle_width_presision_input(f_info, args);
	if (f_info->specifier == 'c')
		ft_print_c_seq(f_info, args, total);
	if (f_info->specifier == 's')
		ft_print_s_seq(f_info, args, total);
	if (ft_strchr("dui", f_info->specifier))
		ft_print_num_seq(f_info, args, total);
	if (ft_strchr("Xx", f_info->specifier))
		ft_print_x_seq(f_info, args, total);
	if (f_info->specifier == 'p')
		ft_print_p_seq(f_info, args, total);
	if (f_info->specifier == '%')
		ft_print_c('%', total);
}

void	ft_parse_sequence(char *str, va_list *args, int *pos, int *total)
{
	int					i;
	char				*valid_sequence;
	t_formatting_info	formatting_info;

	i = 1;
	if (is_specifier(str[i]))
	{
		ft_print_specifier(str[i], args, total);
		*pos += i;
	}
	else if (is_flag(str[i]) || ft_strchr(".*", str[i]) || ft_isdigit(str[i]))
	{
		valid_sequence = extract_valid_sequence(&str[i], pos);
		if (valid_sequence)
		{
			formatting_info = store_sequence_information(valid_sequence);
			free(valid_sequence);
			ft_print_sequence(&formatting_info, args, total);
		}
		else
			ft_print_c('%', total);
	}
	else
		ft_print_c('%', total);
}
