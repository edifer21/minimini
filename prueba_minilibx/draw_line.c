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
// gcc draw_line.c -o draw_line -Iminilibx-linux -Lminilibx-linux -lmlx -lXext -lX11 -lbsd

int	mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y, int color);

void	drawline(void *mlx_ptr, void *win_ptr, 
				int x0, int y0, int x1, int y1, int color)
{
	int		dx;
	int		dy;
	float	m;
	int		i;

	dx = x1 - x0;
	dy = y1 - y0;
	if (dx != 0)
	{
		m = (float)dy / dx;
		i = 0;
		while (i <= dx)
		{
			mlx_pixel_put (mlx_ptr, win_ptr, x0 + i, y0 + (int)(i * m), color);
			i++;
		}
	}

}


int	main( void )
{
	void	*win;
	void	*mlx;

	mlx = mlx_init();
	win = mlx_new_window (mlx, 500, 500, "DIBUJA");
	drawline(mlx, win, 50, 50, 200, 50, 0xFFFFFF);

	// Dibujar líneas de prueba
	drawline(mlx, win, 50, 100, 300, 100,0xFFF000);  // Línea horizontal (amarillo)
	drawline(mlx, win, 100, 100, 100, 300, 0x00FF00); // Línea vertical (verde)
	drawline(mlx, win, 70, 70, 200, 150, 0xFFFFFF);  // Línea diagonal (blanco)
	mlx_loop(mlx);
	return (0);
}
