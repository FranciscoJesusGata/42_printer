/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:12:55 by fgata-va          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/01/27 15:31:13 by fgata-va         ###   ########.fr       */
=======
/*   Updated: 2020/02/04 20:57:16 by fgata-va         ###   ########.fr       */
>>>>>>> b690533ca886ef1d690a7ce3230385e8b6ffcf6e
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
	if(data->width > 0 && data->minus == 1)
		ft_width(data->width, 1, data);
}

void	ft_percent(t_flags *data)
{
	data->printed += write(1, "%" ,1);
}
