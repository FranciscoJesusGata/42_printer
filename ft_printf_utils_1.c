/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:17:05 by fgata-va          #+#    #+#             */
/*   Updated: 2020/01/24 18:03:45 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_write_str(char *str, t_list *data)
{
	int i;

	i = 0;
	while (str[i] && i < data->presition)
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
