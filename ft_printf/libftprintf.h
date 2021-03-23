/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bde-luca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 16:47:27 by bde-luca          #+#    #+#             */
/*   Updated: 2021/02/23 15:54:20 by bde-luca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

typedef struct		s_struct
{
	int				minus;
	int				zero;
	int				width;
	int				precision;
	int				type_lenght;
	char			type_char;
	char			*type_arg_s;
	char			type_arg_c;
	int				type_arg_d;
	unsigned int	type_arg_x;
	unsigned int	type_arg_xup;
	unsigned int	type_arg_u;
	size_t			type_arg_p;
	int				fillers;
	int				format_lenght;
	int				num_neg;
	int				fill_width;
	int				fill_prec;
	int				spaces;
	size_t			meno_uno;
}					t_struct;

int					ft_sup_printf(t_struct *list, const char *str,
					va_list argptr, int *i);
void				ft_parse(t_struct *list, const char *str,
					va_list argptr, int *i);
void				ft_init_struct(t_struct *list);
int					ft_printf(const char *str, ...);
int					ft_atoi(const char *str, int *i);
int					ft_isdigit(int c);
int					ft_putnbr(t_struct *list, int nb);
void				ft_putchar(char c);
int					ft_putstrlen(t_struct *list, char *s);
int					ft_strlen(t_struct *list, char *s);
void				ft_putstr(t_struct *list, char *s);
int					ft_countnbr(t_struct *list, int nb);
void				ft_check_num_neg(t_struct *list);
void				ft_check_width(t_struct *list, const char *str,
					va_list argptr, int *i);
void				ft_check_precision(t_struct *list, const char *str,
					va_list argptr, int *i);
void				ft_check_type(t_struct *list, const char *str, int *i);
void				ft_check_minus(t_struct *list, const char *str, int *i);
void				ft_check_zero(t_struct *list, const char *str, int *i);
void				ft_alignment(t_struct *list, va_list argptr);
void				ft_left_aligned(t_struct *list, va_list argptr);
void				ft_right_aligned(t_struct *list, va_list argptr);
int					ft_right_check_fillers(t_struct *list);
int					ft_left_check_fillers(t_struct *list);
int					ft_right_negative_d(t_struct *list);
int					ft_right_positive_d(t_struct *list);
void				ft_sup_right_positive(t_struct *list);
void				ft_sup_right_negative_one(t_struct *list);
void				ft_sup_right_negative_two(t_struct *list);
int					ft_left_negative_d(t_struct *list);
int					ft_left_positive_d(t_struct *list);
void				ft_process_type(va_list argptr, t_struct *list);
void				ft_process_type_one(va_list argptr, t_struct *list);
void				ft_process_type_two (va_list argptr, t_struct *list);
void				ft_process_type_three (va_list argptr, t_struct *list);
int					ft_filler(t_struct *list, int n);
int					ft_filler_precision(t_struct *list);
void				ft_print_type(t_struct *list);
void				ft_putminus(t_struct *list);
int					ft_counthexa_upper(t_struct *list, size_t n);
int					ft_hexa_upper(char *hexadecinum, int len, int i, size_t n);
int					ft_counthexa_lower(t_struct *list, size_t n);
int					ft_hexa_lower(char *hexadecinum, int len, int i, size_t n);
void				ft_puthexa_lower(t_struct *list, size_t n);
void				ft_puthexa_upper(t_struct *list, size_t n);
void				ft_putnbr_u(t_struct *list, unsigned int nb);
int					ft_countnbr_u(t_struct *list, unsigned int nb);

#endif
