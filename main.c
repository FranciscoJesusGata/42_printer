/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgata-va <fgata-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 13:35:47 by fgata-va          #+#    #+#             */
/*   Updated: 2020/01/27 15:36:51 by fgata-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int mine;
	int native;

	printf("Tester simple de printf:\n(El primer resultado es de ft_printf y el segundo es el de printf)\n");
	printf("====================TEST 1====================\n");
	printf("Test con format sin variables: \n");
	mine = ft_printf("Hola mundo. \n");
	native = printf("Hola mundo. \n");
	printf("Mi función escribió %d y printf escribió %d \n", mine, native);
	printf("====================TEST 2====================\n");
	printf("Test con carácteres simples\n");
	mine = ft_printf("Hola %c. \n", 'a');
	native = printf("Hola %c. \n", 'a');
	printf("Mi función escribió %d y printf escribió %d \n", mine, native);
	printf("====================TEST 3====================\n");
	printf("Test con un string simple\n");
	mine = ft_printf("Hola %s. \n", "mundo");
	native = printf("Hola %s. \n", "mundo");
	printf("Mi función escribió %d y printf escribió %d \n", mine, native);
	printf("====================TEST 4====================\n");
	printf("Test con varios strings\n");
	mine = ft_printf("Hola %s, %s, %s. \n", "Curro", "Alberto", "Jaime");
	native = printf("Hola %s, %s, %s. \n", "Curro", "Alberto", "Jaime");
	printf("Mi función escribió %d y printf escribió %d \n", mine, native);
	printf("====================TEST 5====================\n");
	printf("Test con varios strings con diferente precisión\n");
	mine = ft_printf("Hola %.3s, %.4s, %.0s. \n", "Curro", "Alberto", "Jaime");
	native = printf("Hola %.3s, %.4s, %.0s. \n", "Curro", "Alberto", "Jaime");
	printf("Mi función escribió %d y printf escribió %d \n", mine, native);
	printf("====================TEST 6====================\n");
	printf("Test con varios strings con width\n");
	mine = ft_printf("Width de 10: |%10s|\n", "Curro");
	native = printf("Width de 10: |%10s|\n", "Curro");
	printf("Mi función escribió %d y printf escribió %d \n", mine, native);
	printf("====================TEST 7====================\n");
	printf("Test con varios chars con width\n");
	mine = ft_printf("Width de 10: |%10c|\n", 'm');
	native = printf("Width de 10: |%10c|\n", 'm');
	printf("Mi función escribió %d y printf escribió %d \n", mine, native);
	printf("====================TEST 8====================\n");
	printf("Test con varios chars con width justificado a la izquierda\n");
	mine = ft_printf("Width de 10: |%-10c|\n", 'm');
	native = printf("Width de 10: |%-10c|\n", 'm');
	printf("Mi función escribió %d y printf escribió %d \n", mine, native);
	printf("====================TEST 9====================\n");
	printf("Test con varios strings con width justificado a la izquierda\n");
	mine = ft_printf("Width de 10: |%-10s|\n", "Curro");
	native = printf("Width de 10: |%-10s|\n", "Curro");
	printf("Mi función escribió %d y printf escribió %d \n", mine, native);
	printf("====================TEST 10====================\n");
	printf("Test con strings con precisión sin especificar\n");
	mine = ft_printf("Hola %.s. \n", "Mundo");
	native = printf("Hola %.s. \n", "Mundo");
	printf("Mi función escribió %d y printf escribió %d \n", mine, native);
	printf("====================TEST 11====================\n");
	printf("Test básico de números enteros\n");
	mine = ft_printf("Tengo una playlist de %d canciones\n", 20);
	native = printf("Tengo una playlist de %d canciones\n", 20);
	printf("Mi función escribió %d y printf escribió %d \n", mine, native);
	printf("====================TEST 12====================\n");
	printf("Test básico de números enteros con el flag 0\n");
	mine = ft_printf("Dos en binario es %04d\n", 10);
	native = printf("Dos en binario es %04d\n", 10);
	printf("Mi función escribió %d y printf escribió %d \n", mine, native);
	printf("====================TEST 13====================\n");
	printf("Test básico de números enteros con width\n");
	mine = ft_printf("Width de 10: |%10d|\n", 10);
	native = printf("Width de 10: |%10d|\n", 10);
	printf("Mi función escribió %d y printf escribió %d \n", mine, native);
	printf("====================TEST 14====================\n");
	printf("Test básico de números enteros con width y justificado a la izq.\n");
	mine = ft_printf("Width de 10: |%-10d|\n", 10);
	native = printf("Width de 10: |%-10d|\n", 10);
	printf("Mi función escribió %d y printf escribió %d \n", mine, native);
	return (0);
}
