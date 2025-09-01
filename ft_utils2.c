/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuqare <mabuqare@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 18:11:56 by mabuqare          #+#    #+#             */
/*   Updated: 2025/08/31 12:33:45 by mabuqare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	append_string_padding(char *str, int padding_num, char padding_char,
		int *pos)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while ((padding_num--) > 0)
		str[i++] = padding_char;
	*pos = i;
}

void	copy_pad_str(t_formatting_info *f_info, char *str, char *input_str)
{
	int	pad_num;
	int	input_len;
	int	i;

	i = 0;
	input_len = (int)ft_strlen(input_str);
	pad_num = f_info->width - input_len;
	if (f_info->sign_char && f_info->padding_char == '0')
	{
		str[i++] = f_info->sign_char;
		pad_num--;
	}
	if (f_info->justify_left)
	{
		ft_strlcpy(&str[i], input_str, input_len + 1);
		append_string_padding(str, pad_num, f_info->padding_char, &i);
	}
	else
	{
		append_string_padding(str, pad_num, f_info->padding_char, &i);
		ft_strlcpy(&str[i], input_str, input_len + 1);
	}
	str[f_info->width] = '\0';
}

int	ft_num_len(unsigned long long int num, int base)
{
	int	len;

	len = 1;
	while (num / base)
	{
		len++;
		num /= base;
	}
	return (len);
}

char	*ft_long_itoa_base(unsigned long long int n, int base, char *digits)
{
	int		len;
	char	*itoa;

	len = ft_num_len(n, base);
	itoa = ft_calloc((len + 1), sizeof(char));
	if (!itoa)
		return (NULL);
	itoa[len--] = '\0';
	while (len >= 0)
	{
		itoa[len--] = (digits[n % base]);
		n /= base;
	}
	return (itoa);
}

char	*ft_ptoa(void *ptr)
{
	int					len;
	char				*ptoa;
	char				*digits;
	unsigned long long	ptr_int;

	ptr_int = (unsigned long long)ptr;
	digits = "0123456789abcdef";
	if (!ptr)
		return (ft_strdup("(nil)"));
	len = ft_num_len(ptr_int, 16);
	ptoa = ft_calloc((len + 1), sizeof(char));
	if (!ptoa)
		return (NULL);
	ptoa[len--] = '\0';
	while (len >= 0)
	{
		ptoa[len--] = (digits[ptr_int % 16]);
		ptr_int /= 16;
	}
	return (ptoa);
}
