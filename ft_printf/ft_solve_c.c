/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yang <yang@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/20 11:46:36 by yang              #+#    #+#             */
/*   Updated: 2021/07/02 11:19:17 by yang             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <wchar.h>

void	ft_convert_unicode(wchar_t c, char *unicode, size_t *byte)
{
	if (0x000080 <= c && c <= 0x0007FF)
	{
		unicode[0] = ((c >> 6) & 0x1F) | 0xC0;
		unicode[1] = ((c >> 0) & 0x3F) | 0x80;
		*byte = 2;
	}
	else if (0x000800 <= c && c <= 0x00FFFF)
	{
		unicode[0] = ((c >> 12) & 0x0F) | 0xE0;
		unicode[1] = ((c >> 6) & 0x3F) | 0x80;
		unicode[2] = ((c >> 0) & 0x3F) | 0x80;
		*byte = 3;
	}
	else if (0x010000 <= c && c <= 0x10FFFF)
	{
		unicode[0] = ((c >> 18) & 0x07) | 0xF0;
		unicode[1] = ((c >> 12) & 0x0F) | 0xE0;
		unicode[2] = ((c >> 6) & 0x3F) | 0x80;
		unicode[3] = ((c >> 0) & 0x3F) | 0x80;
		*byte = 4;
	}
}

void	ft_solve_wchar(t_info *info, wchar_t c)
{
	char	unicode[5];
	size_t	byte;

	byte = 0;
	if (0x000000 <= c && c <= 0x00007F)
	{
		unicode[0] = ((c >> 0) & 0x7F) | 0x00;
		byte = 1;
	}
	else
		ft_convert_unicode(c, unicode, &byte);
	unicode[byte] = '\0';
	info->total_length += write(1, unicode, byte);
}

void	ft_solve_char(t_info *info)
{
	unsigned char	c;

	if (!info->flag_minus)
	{
		while (--info->width > 0)
			info->total_length += write(1, " ", 1);
	}
	if (info->modifier == 0)
	{
		c = (unsigned char)va_arg(info->arguments, int);
		info->total_length += write(1, &c, 1);
	}
	else if (info->modifier == LONG)
		ft_solve_wchar(info, va_arg(info->arguments, wchar_t));
	while (--info->width > 0)
		info->total_length += write(1, " ", 1);
}

size_t	ft_unistrlen(const wchar_t *s)
{
	const wchar_t	*ptr;
	size_t			i;

	ptr = s;
	i = 0;
	while (ptr[i] != '\0')
		i++;
	return (i);
}
