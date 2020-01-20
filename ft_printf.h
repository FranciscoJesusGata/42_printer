/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:10:34 by fgata-va          #+#    #+#             */
/*   Updated: 2020/01/20 21:40:56 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define ALLSIMBOLS "cspdiuxX%-.*0123456789"
# define CONVERSIONS "cspdiuxX%"
# include <stdarg.h>
# include "Libft/libft.h"

typedef struct printf_s
{
	char	*str;
	int		printed;

	int		minus;
	int		zero;
	int		precision;
	int		width;
} 			d_list;

int			ft_printf(const char *, ...);

#endif