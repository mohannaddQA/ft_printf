/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_sequence_information_bonus.c             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuqare  <mabuqare@student.42amman.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 21:44:33 by mabuqare          #+#    #+#             */
/*   Updated: 2025/08/29 19:35:54 by mabuqare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	initialize_sequence_information(t_formatting_info *f_info, char *str)
{
	f_info->specifier = str[ft_strlen(str) - 1];
	f_info->padding_char = ' ';
	f_info->width = 0;
	f_info->precision = -1;
	f_info->justify_left = 0;
	f_info->sign_char = '\0';
	f_info->hex_prefix = 0;
}

void	store_flag_information(t_formatting_info *f_info, char *str, int *i)
{
	char	*flags;

	while (is_flag(str[*i]))
		(*i)++;
	flags = ft_substr(str, 0, *i);
	if (ft_strchr(flags, '-'))
		f_info->justify_left = 1;
	else if (ft_strchr(flags, '0') && !ft_strchr("sc", f_info->specifier))
		f_info->padding_char = '0';
	if (ft_strchr(flags, '+') && f_info->specifier != 'u')
		f_info->sign_char = '+';
	else if (ft_strchr(flags, ' ') && f_info->specifier != 'u')
		f_info->sign_char = ' ';
	if (ft_strchr(flags, '#'))
		f_info->hex_prefix = 1;
	free(flags);
}

void	store_width_information(t_formatting_info *f_info, char *str, int *i)
{
	if (str[*i] == '*')
	{
		f_info->width = -1;
		(*i)++;
		return ;
	}
	f_info->width = ft_atoi(&str[*i]);
	while (ft_isdigit(str[*i]))
		(*i)++;
}

void	store_precision_information(t_formatting_info *f_info, char *str,
		int *i)
{
	if (str[*i] == '.')
	{
		(*i)++;
		f_info->padding_char = ' ';
		if (str[*i] == '*')
		{
			f_info->precision = -2;
			(*i)++;
			return ;
		}
		f_info->precision = ft_atoi(&str[*i]);
		while (ft_isdigit(str[*i]))
			(*i)++;
	}
}

t_formatting_info	store_sequence_information(char *str)
{
	t_formatting_info	formatting_info;
	int					i;

	i = 0;
	initialize_sequence_information(&formatting_info, str);
	store_flag_information(&formatting_info, str, &i);
	store_width_information(&formatting_info, str, &i);
	store_precision_information(&formatting_info, str, &i);
	return (formatting_info);
}
