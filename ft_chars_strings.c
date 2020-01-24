/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:12:55 by fgata-va          #+#    #+#             */
/*   Updated: 2020/01/24 18:02:55 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strings(va_list ap, t_flags *data)
{
	const char *str;

	str = (const char *)va_arg(ap, const char *);
	data->printed += ft_write_str((char *)str, data);
}

void	ft_chars(va_list ap, t_flags *data)
{
	char c;

	c = va_arg(ap, int);
	data->printed += write(1, &c, 1);
}
