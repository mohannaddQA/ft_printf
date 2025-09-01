/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabuqare  <mabuqare@student.42amman.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:32:37 by mabuqare          #+#    #+#             */
/*   Updated: 2025/09/01 11:54:21 by mabuqare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

/* ----- Structs ---- */
typedef struct s_formatting_info
{
	int				width;
	char			padding_char;
	int				justify_left;
	int				precision;
	char			sign_char;
	int				hex_prefix;
	char			specifier;
}					t_formatting_info;
/*-------printf---------*/
int					ft_printf(const char *str, ...);
/*-------Parser---------*/
void				ft_parse_sequence(char *str, va_list *args, int *pos,
						int *total);
/*-------Numbers--------*/
void				ft_puthex(unsigned int num, int has_prefix,
						char prefix_char);
void				ft_putunbr_fd(unsigned int n, int fd);
int					ft_num_len(unsigned long long int num, int base);
char				*ft_long_itoa_base(unsigned long long int n, int base,
						char *digits);
char				*ft_ptoa(void *ptr);
/*-------Checkers-------*/
int					is_specifier(char specifier);
int					is_flag(char c);
int					is_valid_width(char *str, int *i);
int					is_valid_precision(char *str, int *i);
/* --- String Modifiers --- */
void				copy_pad_str(t_formatting_info *f_info, char *str,
						char *input_str);
void				append_string_padding(char *str, int padding_num,
						char padding_char, int *pos);
/*------- Prints --------*/
void				ft_print_c(char c, int *total);
void				ft_print_s(char *str, int *total);
void				ft_print_i(int num, int *total);
void				ft_print_u(unsigned int num, int *total);
void				ft_print_p(void *ptr, int *total);
void				ft_print_x(unsigned int num, int prefix, char prefix_char,
						int *total);
void				ft_print_specifier(char c, va_list *args, int *total);
/*------------------------------ Bonus --------------------------------*/
/*--- Sequence handlers ---*/
char				*extract_valid_sequence(char *str, int *pos);
t_formatting_info	store_sequence_information(char *str);
/*-------Prints --------*/
void				ft_print_sequence(t_formatting_info *formatting_info,
						va_list *args, int *total);
void				ft_print_s_seq(t_formatting_info *f_info, va_list *args,
						int *total);
void				ft_print_c_seq(t_formatting_info *f_info, va_list *args,
						int *total);
void				ft_print_num_seq(t_formatting_info *f_info, va_list *args,
						int *total);
void				ft_print_x_seq(t_formatting_info *f_info, va_list *args,
						int *total);
void				ft_print_p_seq(t_formatting_info *f_info, va_list *args,
						int *total);
#endif
