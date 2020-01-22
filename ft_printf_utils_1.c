/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:17:05 by fgata-va          #+#    #+#             */
/*   Updated: 2020/01/22 18:09:38 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_write_str(char *str)
{
	int	written;

	written = 0;
	while (str)
	{
		written += write(1, str, 1);
		str++;
	}
	return (written);
}
