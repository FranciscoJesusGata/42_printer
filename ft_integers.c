/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 11:58:10 by fgata-va          #+#    #+#             */
/*   Updated: 2020/01/26 12:36:40 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_modified(int n, t_flags *data)
{
	char		c;

	if (n <= 2147483647 && n > -2147483648)
	{
		if (n < 0)
		{
			data->printed += write(1, "-", 1);
			if (n == -2147483648)
			{
				data->printed = write(1, "2", 1);
				n *= -1;
				n = n % 1000000000;
			}
			n *= -1;
		}
		if (n > 9)
		{
			ft_putnbr_modified(n / 10, data);
		}
		c = (n % 10) + '0';
		data->printed += write(1, &c, 1);
	}
}

void		ft_zero(int num, t_flags *data)
{
	int		length;
	int		i;
	
	length = ft_strlen(ft_itoa(num));
	if(data->zero > length)
	{
		i = 0;
		while (i < (data->zero - length))
		{
			data->printed += write(1, "0", 1);
			i++;
		}
	}
}

void		ft_prnt_int(va_list ap, t_flags *data)
{
	int prnt;

	prnt = va_arg(ap, int);
	if(data->zero > 0)
		ft_zero(prnt, data);
	if(data->width > 0 && data->minus != 1)
		ft_width(data->width, ft_strlen(ft_itoa(prnt)), data);
	ft_putnbr_modified(prnt, data);
	if(data->width > 0 && data->minus == 1)
		ft_width(data->width, ft_strlen(ft_itoa(prnt)), data);
}