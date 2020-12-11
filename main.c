/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:06:33 by adelille          #+#    #+#             */
/*   Updated: 2020/12/11 04:28:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_miniRT.h"

t_pixel		*ft_init_t_pixel(int H, int W)
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

int			main(int ac, char **av)
{
	(void)ac;
	(void)av;
// need to check if scene got camera, an ambiance light and a resolution
	unsigned int	H;
	unsigned int	W;
	t_pixel			*pixels;

	H = 1024;
	W = 1024;
	if (!(pixels = ft_init_t_pixel(H, W)))
		return (1);
	//ft_parse(scene, camera, ...)
	ft_save_bmp(pixels, H, W);
	free(pixels);
	return (0);
}
