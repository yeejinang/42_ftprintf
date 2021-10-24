/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 22:28:30 by yang              #+#    #+#             */
/*   Updated: 2021/07/02 11:39:00 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_eval_flag(t_info *info)
{
	while (*info->format == '-' || *info->format == '0'
		|| *info->format == '#' || *info->format == ' '
		|| *info->format == '+')
	{
		info->flag = 1;
		if (*info->format == '-')
			info->flag_minus = 1;
		else if (*info->format == '0')
			info->flag_zero = 1;
		else if (*info->format == '#')
			info->flag_special = 1;
		else if (*info->format == ' ')
			info->flag_space = 1;
		else if (*info->format == '+')
			info->flag_plus = 1;
		info->format++;
	}
}

void	ft_eval_width(t_info *info)
{
	if (ft_isdigit(*info->format))
		info->width = skip_atoi(&info->format);
	if (*info->format == '*')
	{
		info->width = va_arg(info->arguments, int);
		if (info->width < 0)
		{
			info->width = -info->width;
			info->flag_minus = 1;
		}
		info->format++;
	}
}

void	ft_eval_precision(t_info *info)
{
	if (*info->format == '.')
	{
		info->format++;
		if (ft_isdigit(*info->format))
			info->precision = skip_atoi(&info->format);
		else if (*info->format == '*')
		{
			info->precision = va_arg(info->arguments, int);
			info->format++;
		}
		else
			info->precision = -10;
		if (info->precision < 0)
			info->precision = 0;
	}
}

void	ft_eval_modifier(t_info *info)
{
	if (*info->format == 'h')
	{
		info->format++;
		if (*info->format == 'h')
		{
			info->format++;
			info->modifier = SHORTSHORT;
		}
		else
			info->modifier = SHORT;
	}
	else if (*info->format == 'l')
	{
		info->format++;
		if (*info->format == 'l')
		{
			info->format++;
			info->modifier = LONGLONG;
		}
		else
			info->modifier = LONG;
	}
}

int	skip_atoi(const char **format)
{
	int	i;

	i = 0;
	while (ft_isdigit(**format))
		i = i * 10 + *((*format)++) - '0';
	return (i);
}
