/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_seq_diu_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuqare <mabuqare@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 01:56:17 by mabuqare          #+#    #+#             */
/*   Updated: 2025/08/31 14:41:41 by mabuqare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_fill_num_buffer(t_formatting_info *f_info, char *buffer,
		long input_num)
{
	int		i;
	char	*str;
	char	*str_cpy;

	i = 0;
	if (f_info->precision == 0 && !input_num)
		str = ft_strdup("");
	else
		str = ft_long_itoa_base(input_num, 10, "0123456789");
	if (!str)
		return ;
	if (f_info->sign_char && f_info->padding_char == ' ')
		buffer[i++] = f_info->sign_char;
	while (((f_info->precision--) - (int)ft_strlen(str)) > 0)
		buffer[i++] = '0';
	str_cpy = str;
	while (*str)
		buffer[i++] = *str++;
	buffer[i] = '\0';
	free(str_cpy);
}

static char	*ft_create_num_buffer(t_formatting_info *f_info, long input_num)
{
	int		buffer_len;
	char	*buffer;
	int		num_len;

	num_len = ft_num_len(input_num, 10);
	buffer_len = num_len;
	if (f_info->sign_char && f_info->padding_char == ' ')
		buffer_len++;
	if (f_info->precision > num_len)
		buffer_len += (f_info->precision - num_len);
	buffer = ft_calloc((buffer_len + 1), sizeof(char));
	if (!buffer)
		return (NULL);
	ft_fill_num_buffer(f_info, buffer, input_num);
	return (buffer);
}

static char	*ft_create_full_buffer(t_formatting_info *f_info, long input_num)
{
	int		full_buffer_len;
	char	*full_buffer;
	char	*num_buffer;

	num_buffer = ft_create_num_buffer(f_info, input_num);
	full_buffer_len = ft_strlen(num_buffer);
	if (f_info->sign_char && f_info->padding_char == '0')
		full_buffer_len++;
	if (f_info->width > full_buffer_len)
		full_buffer_len += (f_info->width - full_buffer_len);
	else
		f_info->width = full_buffer_len;
	full_buffer = ft_calloc((full_buffer_len + 1), sizeof(char));
	if (!full_buffer)
		return (NULL);
	copy_pad_str(f_info, full_buffer, num_buffer);
	free(num_buffer);
	return (full_buffer);
}

void	ft_print_num_seq(t_formatting_info *f_info, va_list *args, int *total)
{
	long int	input_num;
	char		*full_buffer;

	if (f_info->specifier == 'u')
		input_num = (long)va_arg(*args, unsigned int);
	else
	{
		input_num = (long)va_arg(*args, int);
		if (input_num < 0)
		{
			input_num *= -1;
			f_info->sign_char = '-';
		}
	}
	full_buffer = ft_create_full_buffer(f_info, input_num);
	if (!full_buffer)
		return ;
	ft_print_s(full_buffer, total);
	free(full_buffer);
}
