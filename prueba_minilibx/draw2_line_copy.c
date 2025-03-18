/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patferna <patferna@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-11 12:36:11 by patferna          #+#    #+#             */
/*   Updated: 2025-03-11 12:36:11 by patferna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <mlx.h>
//Bresenham
// gcc draw2_line_copy.c -o draw_copy -Iminilibx-linux -Lminilibx-linux -lmlx -lXext -lX11 -lbsd

void drawline(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1, int color)
{
	if (x0 > x1)
	{
		int temp = x0;
		x0 = x1;
		x1 = temp;

		temp = y0;
		y0 = y1;
		y1 = temp;
	}

	int dx = x1 - x0;
	int dy = y1 - y0;
	int dir = (dy < 0) ? -1 : 1;
	dy *= dir;

	if (dx != 0)
	{
		int y = y0;
		int p = 2 * dy - dx;

		for (int i = 0; i <= dx; i++)
		{
		mlx_pixel_put(mlx_ptr, win_ptr, x0 + i, y, color);
			if (p >= 0)
			{
				y += dir;
				p -= 2 * dx;
			}
			p += 2 * dy;
		}
	}
}



int	main( void )
{
	void	*win_ptr;
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window (mlx_ptr, 500, 500, "DIBUJA");
	drawline(mlx_ptr, win_ptr, 50, 50, 200, 50, 0xFFFFFF);

	// Dibujar líneas de prueba
	drawline(mlx_ptr, win_ptr, 60, 60, 200, 60, 0xFF0000);  // Línea horizontal (rojo)
	drawline(mlx_ptr, win_ptr, 100, 100, 100, 300, 0x00FF00); // Línea vertical (verde)
	drawline(mlx_ptr, win_ptr, 50, 100, 300, 100, 0xFFF000); // Línea rojo
	mlx_loop(mlx_ptr);
	return (0);
}
