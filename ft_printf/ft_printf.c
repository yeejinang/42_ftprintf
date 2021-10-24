/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 20:57:01 by yang              #+#    #+#             */
/*   Updated: 2021/07/02 11:36:04 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_initialize_info(t_info *info)
{
	info->sign = 0;
	info->flag = 0;
	info->flag_minus = 0;
	info->flag_zero = 0;
	info->flag_special = 0;
	info->flag_space = 0;
	info->flag_plus = 0;
	info->width = 0;
	info->precision = -1;
	info->digit_signed = 0;
	info->modifier = 0;
}

void	ft_eval_datatype(t_info *info)
{
	if (*info->format == 'c')
		ft_solve_char(info);
	else if (*info->format == 's')
		ft_solve_string_bonus(info);
	else if (*info->format == 'p')
		ft_solve_digit(info, 16);
	else if (*info->format == 'd'
		|| *info->format == 'i' || *info->format == 'u')
		ft_solve_digit(info, 10);
	else if (*info->format == 'x' || *info->format == 'X')
		ft_solve_digit(info, 16);
	else if (*info->format == '%')
		info->total_length += write(1, "%", 1);
	else if (*info->format == 'n')
		ft_eval_args_n(info);
}

void	ft_eval_input(t_info *info)
{
	info->format++;
	ft_eval_flag(info);
	ft_eval_width(info);
	ft_eval_precision(info);
	ft_eval_modifier(info);
	ft_eval_datatype(info);
}

int	ft_printf(const char *format, ...)
{
	t_info	*info;
	int		len;

	len = 0;
	info = (t_info *)ft_calloc(sizeof(t_info), 1);
	ft_initialize_info(info);
	info->total_length = 0;
	va_start(info->arguments, format);
	info->format = format;
	while (*info->format)
	{
		if (*info->format == '%')
		{
			ft_eval_input(info);
			ft_initialize_info(info);
		}
		else
			info->total_length += write(1, info->format, 1);
		info->format++;
	}
	va_end(info->arguments);
	len = info->total_length;
	free(info);
	return (len);
}
