/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:06:33 by adelille          #+#    #+#             */
/*   Updated: 2020/12/12 09:49:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_miniRT.h"

t_pixel			*ft_init_t_pixel(int H, int W)
{
	int				i;
	t_pixel			*pixels;

	if (!(pixels = malloc(sizeof(t_pixel) * H * W)))
	{
		ft_error("", -1);
		return (NULL);
	}
	i = 0;
	while (i <= H * W)
	{
		pixels[i].R = 255;
		pixels[i].G = 0;
		pixels[i].B = 0;
		i++;
	}
	return (pixels);
}

int			ft_render(t_pixel *pixels, int H, int W, char **av)
{
	if (av[1] == (char *)"-save" || av[2] == (char *)"-save")
		ft_save_bmp(pixels, H, W);
	if (av[1] == (char *)"-png" || av[2] == (char *)"-png")
		ft_putstr_fd("the -png fonction hasn't been code yet\n", 1);
		// ft_save_png
	if (ft_mlx_init(pixels, H, W) == -1)
		return (ft_error("mlx return -1 for some reason\n", 0));
	return (0);
}

int			main(int ac, char **av)
{
	(void)ac;
// need to check if scene got camera, an ambiance light and a resolution
	unsigned int	H;
	unsigned int	W;
	t_pixel			*pixels;

	H = 1024;
	W = 1024;
	if (!(pixels = ft_init_t_pixel(H, W)))
		return (1);
	//ft_parse(scene, camera, ...)
	ft_render(pixels, H, W, av);
	free(pixels);
	return (0);
}
