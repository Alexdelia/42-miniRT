/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:17:04 by adelille          #+#    #+#             */
/*   Updated: 2021/01/29 16:32:22 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_color		ft_light_hit(t_inter inter, t_scene scene, int i, t_color color)
{
	t_ray		ray_l;
	t_phong		phong;
	t_inter		inter_l;

	ray_l.origin = ft_add(inter.coord, ft_scale(inter.normal, 0.001));
	ray_l.direction = ft_normalize(ft_sub(scene.lights.pos[i], inter.coord));
	inter_l = ft_objs_inter(scene, ray_l, inter.id);
	if (inter_l.hit == TRUE && inter_l.t < scene.lights.distance[i])
		color.is_in_shadow = TRUE;
	else
	{
		color.is_in_shadow = FALSE;
		phong = ft_phong(inter.ray, inter, scene.lights.pos[i]);
	}
}

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
		while (++i < scene.nb_of.lights)
		{
			scene.lights.distance[i] = get_norm(ft_sub(scene.lights.pos[i],
							inter.coord));
			scene.lights.dir[i] = (ft_sub(scene.lights.pos[i],
							inter.coord));
			tmp = ft_light_hit(inter, scene, i, color);
		}
	}
}
