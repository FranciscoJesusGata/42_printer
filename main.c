/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:35:47 by fgata-va          #+#    #+#             */
/*   Updated: 2020/01/24 18:29:04 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int mine;
	int native;

	mine = ft_printf("Hola mundo \n");
	native = printf("Hola mundo \n");
	printf("Mi función escribió %d y printf escribió %d \n", mine, native);
	mine = ft_printf("Hola %c \n", 'a');
	native = printf("Hola %c \n", 'a');
	printf("Mi función escribió %d y printf escribió %d \n", mine, native);
	mine = ft_printf("Hola %s \n", "mundo");
	native = printf("Hola %s \n", "mundo");
	printf("Mi función escribió %d y printf escribió %d \n", mine, native);
	mine = ft_printf("Hola %.3s, %s, %s \n", "Curro", "Alberto", "Jaime");
	native = printf("Hola %.3s, %s, %s \n", "Curro", "Alberto", "Jaime");
	printf("Mi función escribió %d y printf escribió %d \n", mine, native);
	return (0);
}
