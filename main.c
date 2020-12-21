/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:06:33 by adelille          #+#    #+#             */
/*   Updated: 2020/12/21 09:29:56 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_miniRT.h"

t_pixel			*ft_init_t_pixel(unsigned int H, unsigned int W)
{
	t_pixel			*pixels;

	if (!(pixels = malloc(sizeof(t_pixel) * H * W)))
	{
		ft_error("", MALLOC);
		return (NULL);
	}
	pixels->H = H;
	pixels->W = W;
	return (pixels);
}

int			ft_render(t_pixel *pixels, char **av)
{
	if (ft_render_call(pixels, &scene) == -1)
		return (ft_error("ray tracing fail for some reason\n", 0));
	if (av[1] == (char *)"-save" || av[2] == (char *)"-save")
		ft_save_bmp(pixels);
	if (av[1] == (char *)"-png" || av[2] == (char *)"-png")
		ft_putstr_fd("the -png fonction hasn't been code yet\n", 0);
		// ft_save_png
	if (!av[1])
	{
		if (ft_mlx_init(pixels) == -1)
			return (ft_error("mlx return -1 for some reason\n", 0));
	}
	return (0);
}

int			main(int ac, char **av)
{
	(void)ac;
// need to check if scene got camera, an ambiance light and a resolution
	t_pixel			*pixels;
	t_scene			scene;

	if (!(pixels = ft_init_t_pixel(1024, 1024)))
		return (1);
	ft_init_scene(&scene);
	ft_parse(av, &scene);
	ft_render(pixels, av);
	free(pixels);
	return (0);
}
