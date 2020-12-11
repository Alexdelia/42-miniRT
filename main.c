/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:06:33 by adelille          #+#    #+#             */
/*   Updated: 2020/12/11 03:34:27 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_miniRT.h"

int		ft_init_t_pixel(t_pixel** pixels, int H, int W)
{
	int				i;
	int				j;

	if (!(pixels = malloc(sizeof(t_pixel) * H * W)))
		return (-1);
	i = 0;
	while (i <= H)
	{
		j = 0;
		while (j <= W)
		{
			pixels[i][j]->R = 255;
			pixels[i][j]->G = 0;
			pixels[i][j]->B = 0;
			j++;
		}
		i++;
	}
	return (0);
}

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
// need to check if scene got camera, an ambiance light and a resolution
	unsigned int	H;
	unsigned int	W;

	H = 1024;
	W = 1024;
	if ((ft_init_t_pixel(t_pixel** pixels, H, W)) == -1)
		return (ft_error("", -1));
	//ft_parse(scene, camera, ...)
	ft_save_bmp(pixels, H, W);
	free(pixels);
}
