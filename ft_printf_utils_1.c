/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:17:05 by fgata-va          #+#    #+#             */
/*   Updated: 2020/02/05 20:27:39 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				ft_reset_data(t_flags *data)
{
	data->minus = 0;
	data->zero = 0;
	data->precision = 0;
	data->precision_l = 0;
	data->width = 0;
}

void				ft_getwidth(const char *f, int *i, t_flags *d, va_list ap)
{
	if (f[*i] == '*')
	{
		d->width = va_arg(ap, int);
		i += 1;
	}
	else
	{
		d->width = ft_atoi(f + *i);
		while (ft_isdigit(f[*i]))
			*i += 1;
		*i -= 1;
	}
}

void				ft_width(int width, int str_length, t_flags *data)
{
	int				i;

	if (data->precision == 1 && data->precision_l < str_length)
		str_length -= data->precision_l - 1;
	if (str_length < width)
	{
		i = 0;
		while (i < (width - str_length))
		{
			data->printed += write(1, " ", 1);
			i++;
		}
	}
}

int					ft_control_star(const char *f, int *i, va_list ap)
{
	int				num;

	num = 0;
	*i += 1;
	if (ft_strchr("123456789", f[*i]))
	{
		num = ft_atoi(f + *i);
		while (ft_isdigit(f[*i + 1]))
			*i += 1;
	}
	else if ('*' == f[*i])
	{
		num = va_arg(ap, int);
	}
	else
		*i += 1;
	return (num);
}

int					ft_write_str(char *str, t_flags *data)
{
	unsigned int	i;
	unsigned int	len;

	len = ft_strlen(str);
	i = 0;
	if (data->width > 0 && data->minus != 1)
		ft_width(data->width, len, data);
	if ((data->precision == 1) && data->precision_l < (int)len)
		len = data->precision_l;
	while (i < len)
	{
		write(1, &str[i], 1);
		i++;
	}
	if (data->width > 0 && data->minus == 1)
		ft_width(data->width, ft_strlen(str), data);
	return (i);
}
