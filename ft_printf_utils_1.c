/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:17:05 by fgata-va          #+#    #+#             */
/*   Updated: 2020/01/25 18:29:45 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_reset_data(t_flags *data)
{
	data->minus = 0;
	data->zero = 0;
	data->precision = 0;
	data->precision_l = 0;
	data->width = 0;
}

void	ft_getwidth(const char *f, int *i, t_flags *data)
{
	data->width = ft_atoi(f + *i);
	while (ft_isdigit(f[*i]))
		*i += 1;
	*i -= 1;
}

void	ft_width(int width, int str_lenght, t_flags *data)
{
	int i;

	if(str_lenght < width)
	{
		i = 0;
		while(i < (width - str_lenght))
		{
			data->printed += write(1, " ", 1);
			i++;
		}
	}
}

int		ft_write_str(char *str, t_flags *data)
{
	int i;

	i = 0;
	if(data->width > 0 && data->minus != 1)
		ft_width(data->width, ft_strlen(str), data);
	while (str[i])
	{
		if((data->precision == 1) && data->precision_l <= i)
			break ;
		write(1, &str[i], 1);
		i++;
	}
	if(data->width > 0 && data->minus == 1)
		ft_width(data->width, ft_strlen(str), data);
	return (i);
}
