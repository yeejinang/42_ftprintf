/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 21:37:17 by yang              #+#    #+#             */
/*   Updated: 2021/07/02 11:38:31 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../../libft/libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# define LONGLONG 8
# define LONG 4
# define SHORT 2
# define SHORTSHORT 1

typedef struct s_info
{
	const char	*format;
	long long	nbr;
	char		*number;
	char		*str;
	char		sign;
	va_list		arguments;
	int			flag;
	int			flag_minus;
	int			flag_zero;
	int			flag_special;
	int			flag_space;
	int			flag_plus;
	int			width;
	int			precision;
	int			modifier;
	int			digit_signed;
	int			total_length;
	char		str_special[2];
}	t_info;

int		ft_printf(const char *format, ...);
size_t	ft_unistrlen(const wchar_t *s);
void	ft_eval_flag(t_info *info);
void	ft_eval_width(t_info *info);
void	ft_eval_precision(t_info *info);
void	ft_eval_modifier(t_info *info);
void	ft_eval_args_n(t_info *info);
void	ft_eval_args(t_info *info);
int		skip_atoi(const char **format);
void	ft_solve_char(t_info *info);
void	ft_solve_wchar(t_info *info, wchar_t c);
void	ft_solve_string_bonus(t_info *info);
void	ft_eval_digit_signed(t_info *info);
void	ft_eval_flag_special(t_info *info);
char	*ft_uitoa_base(unsigned long long i, long long base_size);
void	ft_solve_numstring(t_info *base, long long base_size);
void	ft_solve_digit(t_info *info, long long base_size);

#endif
