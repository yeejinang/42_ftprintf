/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 15:45:39 by yang              #+#    #+#             */
/*   Updated: 2021/06/30 21:21:21 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_solve_str(t_info *info, char *str, int len)
{
	int	i;

	i = -1;
	if (info->precision != -1 && info->precision < len)
		len = info->precision;
	if (!info->flag_minus)
	{
		while (len < info->width--)
			info->total_length += write(1, " ", 1);
	}
	while (++i < len)
		info->total_length += write(1, str++, 1);
	while (len < info->width--)
		info->total_length += write(1, " ", 1);
}

void	ft_solve_string(t_info *info)
{
	char	*str;
	int		len;
	int		i;

	len = 0;
	i = -1;
	str = va_arg(info->arguments, char *);
	if (str == NULL)
	{
		str = "(null)";
		if (!info->width)
		{
			while (*str)
				info->total_length += write(1, str++, 1);
			return ;
		}
	}
	len = ft_strlen(str);
	ft_solve_str(info, str, len);
}

void	ft_solve_long_str(t_info *info, wchar_t *str, int len)
{
	int	i;

	i = -1;
	if (info->precision != -1 && info->precision < len)
		len = info->precision;
	if (!info->flag_minus)
	{
		while (len < info->width--)
			info->total_length += write(1, " ", 1);
	}
	while (++i < len)
		ft_solve_wchar(info, str[i]);
	while (len < info->width--)
		info->total_length += write(1, " ", 1);
}

void	ft_solve_long_string(t_info *info)
{
	wchar_t	*str;
	int		len;
	int		i;

	len = 0;
	i = -1;
	str = va_arg(info->arguments, wchar_t *);
	if (str == NULL)
	{
		str = L"(null)";
		if (!info->width)
		{
			while (*str)
				info->total_length += write(1, str++, 1);
			return ;
		}
	}
	len = ft_unistrlen(str);
	ft_solve_long_str(info, str, len);
}

void	ft_solve_string_bonus(t_info *info)
{
	if (info->modifier == LONG)
		ft_solve_long_string(info);
	else
		ft_solve_string(info);
}
