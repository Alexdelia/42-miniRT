/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:13:37 by adelille          #+#    #+#             */
/*   Updated: 2020/12/16 01:57:51 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_miniRT.h"

static int	ft_color_math(t_pixel *pixels, int i)
{
	return (pixels[i].T * 256 * 256 * 256)
				+ (pixels[i].R * 256 * 256)
				+ (pixels[i].G * 256)
				+ (pixels[i].B);
}

static int	ft_mlx_fill_pixel(t_pixel *pixels, void *mlx_ptr, void *win_ptr)
{
	/* int for color is like 	| 	0 		|	R		|	G		|	B	|
	**							1111 1111	1111 1111	1111 1111	1111 1111
	** so 0 255 128 60	= 00000000 11111111 10000000 00111100
	** or				= 16 744 508
	** 0 * 256 * 256 * 256	+
	** R * 256 * 256		+
	** G * 256				+
	** B					+=
	*/
	int				i;
	
	i = -1;
	while (++i <= pixels.H * pixels.W)
		mlx_pixel_put (mlx_ptr, win_ptr, (i / pixels.H), (i % pixels.H),
				ft_color_math(pixels, i));
	return (0);
}

int			ft_mlx_init(t_pixel *pixels)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, pixels.H, pixels.W, "MiniRT");
	ft_mlx_fill_pixel(pixels, mlx_ptr, win_ptr);
	mlx_loop(mlx_ptr);
	// mlx_destroy_window(mlx_ptr, win_ptr);
	return (0);
}
