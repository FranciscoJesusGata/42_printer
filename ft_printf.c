/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:10:38 by fgata-va          #+#    #+#             */
/*   Updated: 2020/01/25 18:15:40 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void		ft_conversions(va_list ap, char c, t_flags *data)
{
	if (c == 'c')
		ft_chrs(ap, data);
	else if (c == 's')
		ft_strings(ap, data);
}

void		ft_modifiers(const char *f, int *i, t_flags *data)
{
	char c;

	c = f[*i];
	if (c == '-')
		data->minus = 1;
	else if (ft_strchr("1234567890", c))
		ft_getwidth(f, i ,data);
	else if (c == '.')
	{
		data->precision = 1;
		data->precision_l = (f[(*i += 1)]) - '0';
	}
	else if (c == '0')
		data->zero = (f[(*i += 1)]) - '0';
}

void		ft_parse_str(t_flags *data, const char *format, va_list ap, int *i)
{
	if (ft_strchr(CONVERSIONS, format[*i]))
	{
		ft_conversions(ap, format[*i], data);
		ft_reset_data(data);
	}
	else
	{
		ft_modifiers(format, i, data);
	}
}

int			ft_manageformat(t_flags *data, const char *format, va_list ap)
{
	int i;

	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
			data->printed += write(1, &format[i], 1);
		else if (format[i] == '%')
		{
			while (ft_strchr(ALLSIMBOLS, format[i]))
			{
				i++;
				ft_parse_str(data, format, ap, &i);
				if (ft_strchr(CONVERSIONS, format[i]))
				{
					i++;
					break ;
				}
			}
			continue;
		}
		i++;
	}
	return (data->printed);
}

int			ft_printf(const char *format, ...)
{
	t_flags	*data;
	va_list ap;
	int		printed;

	va_start(ap, format);
	data = malloc(sizeof(t_flags));
	data->printed = 0;
	ft_manageformat(data, format, ap);
	printed = data->printed;
	free(data);
	return (printed);
}
