/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:17:04 by adelille          #+#    #+#             */
/*   Updated: 2021/01/29 16:13:36 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color		ft_init_color(int color, double ratio)
{
	t_color		rgb;

	rgb.r = ratio * (color & 0xFF) / 255;
	rgb.g = ratio * (color >> 8 & 0xFF) / 255;
	rgb.b = ratio * (color >> 16 & 0xFF) / 255;
	return (rgb);
}

void		ft_render_pixel(t_scene scene, t_img *img, t_ray ray, int index)
{
	size_t		i;
	t_inter		inter;
	t_color		color;
	t_color		tmp;

	inter = ft_objs_inter(scene, ray, -1);
	inter.ray = ray;
	i = -1;
	if (inter.hit == TRUE)
	{
		color = ft_init_color(inter.color, scene.ambient_light_ratio);
	}
}
