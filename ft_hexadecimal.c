/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 19:36:39 by fgata-va          #+#    #+#             */
/*   Updated: 2020/02/11 21:38:59 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_dec_to_hex(long long int num, t_flags *data)
{
	char		c;
	int			h;

	h = num % 16;
	if (num > 0)
	{
		ft_dec_to_hex(num / 16, data);
		if (h > 9)
			c = (h - 10) + 'a';
		else if (h < 9)
			c = h + '0';
		data->printed += write(1, &c, 1);
	}
}

void				ft_print_hex(va_list ap, t_flags *data)
{
	long long int	dec;

	dec = va_arg(ap, int);
	if (data->width > 0 && data->minus != 1)
		ft_width(data->width, ft_totaldgts(data, *dgts), data);
	if (dec == 0)
		data->printed += write(1, "0", 1);
	else
		ft_dec_to_hex(dec, data);
}
