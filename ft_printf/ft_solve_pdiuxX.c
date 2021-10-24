/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_pdiuxX.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 11:40:45 by yang              #+#    #+#             */
/*   Updated: 2021/07/02 11:40:58 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_solve_left(t_info *info, int len, int j, int i)
{
	int		length;
	char	*ptr;
	int		special;

	length = 0;
	ptr = info->number;
	j = len;
	special = -1;
	if (info->sign)
		length += write(1, &info->sign, 1);
	while (info->flag_special == 2 && ++special < 2)
		length += write(1, &info->str_special[special], 1);
	while (j++ < info->precision)
		length += write(1, "0", 1);
	while (i++ < len)
	{
		length += write(1, ptr, 1);
		ptr++;
	}
	while (length < info->width)
		length += write(1, " ", 1);
	info->total_length += length;
}

void	ft_solve_right(t_info *info, int len, int j, int i)
{
	int		k;
	int		length;
	char	*ptr;
	int		special;

	length = 0;
	special = -1;
	ptr = info->number;
	k = info->width;
	while (info->precision < 0 && j++ < info->width && !info->flag_zero)
		length += write(1, " ", 1);
	while (info->precision != -1 && j++ < info->width && k-- > info->precision)
		length += write(1, " ", 1);
	j = len;
	if (info->sign)
		length += write(1, &info->sign, 1);
	while (info->flag_special == 2 && ++special < 2)
		length += write(1, &info->str_special[special], 1);
	while (j++ < info->precision || (info->flag_zero
			&& info->precision == -1 && info->width-- > len))
		length += write(1, "0", 1);
	while (++i - 1 < len)
		length += write(1, ptr++, 1);
	info->total_length += length;
}

void	ft_solve_digit(t_info *info, long long base_size)
{
	int		len;
	int		i;
	int		j;

	i = 0;
	ft_eval_args(info);
	ft_eval_digit_signed(info);
	ft_eval_flag_special(info);
	ft_solve_numstring(info, base_size);
	len = ft_strlen(info->number);
	if (info->precision == -10 && !info->width)
	{
		free(info->number + len - 20);
		return ;
	}
	if (info->precision != -1 && info->precision <= 0 && info->nbr == 0)
		len = 0;
	j = len;
	if (info->flag_minus)
		ft_solve_left(info, len, j, i);
	else
		ft_solve_right(info, len, j, i);
	free(info->number - 24 + ft_strlen(info->number));
}
