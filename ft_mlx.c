/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:13:37 by adelille          #+#    #+#             */
/*   Updated: 2020/12/12 10:01:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_miniRT.h"

int	ft_mlx_init(t_pixel *pixels, int H, int W)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, W, H, "MiniRT");
	mlx_loop(mlx_ptr);
	if (pixels[0].R == 255)
		ft_putstr_fd("pixels[0].R == 255", 1);
	mlx_destroy_window(mlx_ptr, win_ptr);
	return (0);
}
