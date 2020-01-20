/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:10:38 by fgata-va          #+#    #+#             */
/*   Updated: 2020/01/20 21:58:53 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			manageformat(d_list *data, char *format, va_list ap)
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
				if (ft_strchr(CONVERSIONS, format[i]))
				{
					//manage the conversions here
					break ;
				}
				else
					;//manage the modifiers here
			}
			continue;
		}
		i++;
	}
	return (data->printed);
}

int			ft_printf(const char *format, ...)
{
	d_list	*data;
	va_list ap;

	va_start(ap, format);
	data = malloc(sizeof(d_list));
	data->str = format;
	data->printed = 0;
	manageformat(data, format, ap);
	return (0);
}
