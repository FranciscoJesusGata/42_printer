/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 19:20:37 by fgata-va          #+#    #+#             */
/*   Updated: 2020/02/13 19:22:47 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int                 ft_p_len(unsigned long int num)
{
	int i;
	unsigned long int    n;
     
	i = 0;
    n = num;
    if (n == 0)
        return (1);
    while (n > 0)
    {
        n /= 16;
        i++;
    }
    return (i + 2);
}

void					ft_hex_p(unsigned long int n, t_flags *data)
{
	char				c;
	unsigned long int	h;

	c = 0;
	if (n > 0)
	{
		ft_hex_p(n / 16, data);
		h = n % 16;
		if (h > 9)
		{
			c = (h - 10) + 'a';
		}
		else if (h <= 9)
			c = h + '0';
		data->printed += write(1, &c, 1);
	}
}


void					ft_print_pointer(va_list ap, t_flags *data)
{
	unsigned long int	p;
	unsigned int    len;

	p = va_arg(ap, unsigned long int);

    if(!p || p == 0)
		data->printed += write(1, "(nil)", 5);
	else
	{
		len = ft_p_len(p);	
		if (data->width > 0 && data->minus != 1)
			ft_width(data->width, len, data);
		data->printed += write(1, "0x", 2);
		if (data->zero > 0 && data->minus != 1)
        	data->printed += ft_zero(len - 2, data->zero);
		if (data->precision == 1 && data->precision_l > (int)(len - 2))
        	data->printed += ft_zero(len - 2, data->precision_l);
		ft_hex_p(p, data);
		if (data->width > 0 && data->minus == 1)
        	ft_width(data->width, len, data);
	}
}

