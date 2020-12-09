/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:06:33 by adelille          #+#    #+#             */
/*   Updated: 2020/12/09 07:45:32 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

unsigned char	ft_init_pixel_tab(/*H, W*/)
{
	unsigned char	*pixel_tab;
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
		}
		i++
	}
}

int				main(int ac, char **av);
{
// need to check if scene got camera, an ambiance light and a resolution
	unsigned char	*pixel_tab;

	if (!pixel_tab = ft_init_pixel_tab(/*H, W*/))
		return (ft_error(/*malloc*/));
	//ft_parse(scene, ...)
	ft_save_bmp(out.bmp, &pixel_tab[0], W, H);
}
