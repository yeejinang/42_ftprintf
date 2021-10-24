/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_pdiuxX.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 10:36:32 by yang              #+#    #+#             */
/*   Updated: 2021/07/02 11:21:57 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_eval_digit_signed(t_info *info)
{
	if (info->digit_signed)
	{
		if (info->nbr < 0)
		{
			info->sign = '-';
			info->nbr = -info->nbr;
			if (info->width && !info->flag_minus)
				info->width--;
		}
		else if (info->flag && info->flag_plus)
		{
			info->sign = '+';
			if (info->width && !info->flag_minus)
				info->width--;
		}
		else if (info->flag && info->flag_space)
		{
			info->sign = ' ';
			if (info->width && !info->flag_minus)
				info->width--;
		}
	}
}

void	ft_eval_flag_special(t_info *info)
{
	if (info->flag_special && info->nbr)
	{
		if (*info->format == 'x')
		{
			info->flag_special = 2;
			info->str_special[0] = '0';
			info->str_special[1] = 'x';
			if (info->width && !info->flag_minus)
				info->width -= 2;
		}
		if (*info->format == 'X')
		{
			info->flag_special = 2;
			info->str_special[0] = '0';
			info->str_special[1] = 'X';
			if (info->width && !info->flag_minus)
				info->width -= 2;
		}
	}
}

char	*ft_uitoa_base(unsigned long long i, long long base_size)
{
	char	*p;
	char	*base;

	base = "0123456789abcdef";
	p = (char *)malloc(25);
	p = p + 24;
	if (i == 0)
		*--p = '0';
	else
	{
		while (i)
		{
			*--p = base[(i % base_size)];
			i /= base_size;
		}
	}
	return (p);
}

void	ft_solve_numstring(t_info *info, long long base_size)
{
	char		*ptr;

	ptr = NULL;
	if (*info->format == 'd' || *info->format == 'i')
		info->number = ft_uitoa_base(info->nbr, base_size);
	else
		info->number = ft_uitoa_base(info->nbr, base_size);
	if (*info->format == 'p')
	{
		*(--info->number) = 'x';
		*(--info->number) = '0';
	}
	if (*info->format == 'X')
	{
		ptr = info->number;
		while (*ptr)
		{
			*ptr = ft_toupper(*ptr);
			ptr++;
		}
	}
}
