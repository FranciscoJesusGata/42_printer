/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chars_strings.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:12:55 by fgata-va          #+#    #+#             */
/*   Updated: 2020/01/22 18:28:54 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strings(va_list ap, t_flags *data)
{
	char *str;

	str = va_arg(ap, char*);
	data->printed += ft_write_str(str);
}

void	ft_chars(va_list ap, t_flags *data)
{
	char c;

	c = va_arg(ap, int);
	data->printed += write(1, &c, 1);
}
