/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 13:32:04 by yang              #+#    #+#             */
/*   Updated: 2021/07/02 11:37:59 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_eval_args_di(t_info *info)
{
	if (info->modifier == SHORTSHORT)
		info->nbr = (signed char)va_arg(info->arguments, int);
	else if (info->modifier == SHORT)
		info->nbr = (short)va_arg(info->arguments, int);
	else if (!info->modifier)
		info->nbr = va_arg(info->arguments, int);
	else if (info->modifier == LONG)
		info->nbr = va_arg(info->arguments, long int);
	else if (info->modifier == LONGLONG)
		info->nbr = va_arg(info->arguments, long long int);
}

void	ft_eval_args_ouxX(t_info *info)
{
	if (info->modifier == SHORTSHORT)
		info->nbr = (unsigned char)va_arg(info->arguments, int);
	else if (info->modifier == SHORT)
		info->nbr = (unsigned short)va_arg(info->arguments, int);
	else if (!info->modifier)
		info->nbr = va_arg(info->arguments, unsigned int);
	else if (info->modifier == LONG)
		info->nbr = va_arg(info->arguments, unsigned long int);
	else if (info->modifier == LONGLONG)
		info->nbr = va_arg(info->arguments, unsigned long long int);
}

void	ft_eval_args_n(t_info *info)
{
	if (info->modifier == SHORTSHORT)
		*va_arg(info->arguments, signed char *) = info->total_length;
	else if (info->modifier == SHORT)
		*va_arg(info->arguments, short int *) = info->total_length;
	else if (!info->modifier)
		*va_arg(info->arguments, int *) = info->total_length;
	else if (info->modifier == LONG)
		*va_arg(info->arguments, long int *) = info->total_length;
	else if (info->modifier == LONGLONG)
		*va_arg(info->arguments, long long int *) = info->total_length;
}

void	ft_eval_args(t_info *info)
{
	if (*info->format == 'p')
		info->nbr = va_arg(info->arguments, unsigned long);
	else if (*info->format == 'd' || *info->format == 'i')
	{
		info->digit_signed = 1;
		ft_eval_args_di(info);
	}
	else
		ft_eval_args_ouxX(info);
}
