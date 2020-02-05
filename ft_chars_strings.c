/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:12:55 by fgata-va          #+#    #+#             */
/*   Updated: 2020/01/27 15:31:13 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strings(va_list ap, t_flags *data)
{
	const char *str;

	str = (const char *)va_arg(ap, const char *);
	data->printed += ft_write_str((char *)str, data);
}

void	ft_chrs(va_list ap, t_flags *data)
{
	char c;

	c = va_arg(ap, int);
	ft_putnbr_fd(data->width, 1);
	if (data->width >= 0 && data->minus != 1)
	{
		ft_width(data->width, 1, data);
		data->printed += write(1, &c, 1);
	}
	else if (data->width > 0 && data->minus == 1)
	{
		data->printed += write(1, &c, 1);
		ft_width(data->width, 1, data);
	}
	else
		data->printed += write(1, &c, 1);
}
