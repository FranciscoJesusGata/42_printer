/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:10:34 by fgata-va          #+#    #+#             */
/*   Updated: 2020/01/24 18:04:08 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define ALLSIMBOLS "cspdiuxX%-.*0123456789"
# define CONVERSIONS "cspdiuxX%"
# include <stdarg.h>
# include <stdlib.h>
# include "Libft/libft.h"

typedef struct	s_printf
{
	int		printed;
	int		minus;
	int		zero;
	int		precision;
	int		width;
}				t_flags;

int				ft_printf(const char *format, ...);
void			ft_strings(va_list ap, t_flags *data);
void			ft_chars(va_list ap, t_flags *data);
int				ft_write_str(char *str, t_list *data);

#endif
