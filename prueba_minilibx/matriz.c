/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matriz.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patferna <patferna@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-18 13:10:47 by patferna          #+#    #+#             */
/*   Updated: 2025-03-18 13:10:47 by patferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<conio.h>

void	meter_datos(int matriz[12],[19])
{
	int i;
	int n;

	i = 0;
	// Bucle while para recorrer las filas
	while (i < 12)
	{
		n = 0; // Reiniciamos c en cada nueva fila
		// Bucle while para recorrer las columnas
		while (n < 19)
		{
			printf("Ingrese un número para la posición [%d][%d]: ", i, n);
			scanf("%i", &matriz[i][n]);
			n++;
			// Incrementamos c
		}
		i++;
		// Incrementamos f
	}
}

void	main(void)
{
	int matriz[12], [19];
	meter_datos(matriz);
	return(0);
}
// leo lo guardo en una estrucutra y lo meto 