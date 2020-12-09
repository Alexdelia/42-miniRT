/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:06:33 by adelille          #+#    #+#             */
/*   Updated: 2020/12/09 23:46:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_miniRT.h"

unsigned int	*ft_init_pixel_tab(int H, int W)
{
	unsigned int	*pixel_tab;
	int				i;
	int				j;

	if (!(pixel_tab = malloc(sizeof(unsigned char *) * H * W * 3)))
		return (NULL);
	i = 0;
	j = 0;
	while (i <= H)
	{
		while (j <= W)
		{
			pixel_tab[(i * W + j) * 3 + 0] = 255;
			pixel_tab[(i * W + j) * 3 + 1] = 0;
			pixel_tab[(i * W + j) * 3 + 2] = 0;
			j++;
		}
		i++;
	}
	return (pixel_tab);
}

int				main(int ac, char **av)
{
	(void)ac;
	(void)av;
// need to check if scene got camera, an ambiance light and a resolution
	unsigned int	*pixel_tab;
	unsigned int	H;
	unsigned int	W;

	H = 1024;
	W = 1024;
	if (!(pixel_tab = ft_init_pixel_tab(H, W)))
		return (ft_error(-1));
	//ft_parse(scene, camera, ...)
	ft_save_bmp(pixel_tab, H, W);
}
