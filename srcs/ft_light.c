/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:17:04 by adelille          #+#    #+#             */
/*   Updated: 2021/02/01 11:17:40 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_color	ft_light_hit(t_inter inter,
			t_scene scene, int i, t_color color)
{
	t_ray		ray_l;
	t_phong		phong;
	t_inter		inter_l;

	ray_l.origin = ft_add(inter.coord, ft_scale(inter.normal, 0.001));
	ray_l.direction = ft_normalize(ft_sub(scene.lights.pos[i], inter.coord));
	inter_l = ft_objs_inter(scene, ray_l, inter.id);
	if (inter_l.hit == TRUE && inter_l.t < scene.lights.distance[i])
		color.shadow = TRUE;
	else
	{
		color.shadow = FALSE;
		phong = ft_phong(inter.ray, inter, scene.lights.pos[i]);
		ft_add_coef(&color, scene.lights.ratio[i],
					scene.lights.colors[i], phong);
	}
	return (color);
}

static t_color	ft_init_color(int color, double ratio)
{
	t_color		rgb;

	rgb.r = ratio * (color & 0xFF) / 255;
	rgb.g = ratio * (color >> 8 & 0xFF) / 255;
	rgb.b = ratio * (color >> 16 & 0xFF) / 255;
	return (rgb);
}

static void		ft_pixel(t_img *img, int color, int index)
{
	img->buffer[index] = color & 0xFF;
	img->buffer[index + 1] = color >> 8 & 0xFF;
	img->buffer[index + 2] = color >> 16 & 0xFF;
	img->buffer[index + 3] = 0;
}

void			ft_render_pixel(t_scene scene, t_img *img, t_ray ray, int index)
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
			scene.lights.distance[i] = ft_get_norm(ft_sub(scene.lights.pos[i],
							inter.coord));
			scene.lights.dir[i] = (ft_sub(scene.lights.pos[i],
							inter.coord));
			tmp = ft_light_hit(inter, scene, i, color);
			if (tmp.shadow == FALSE)
				color = ft_coef_p_coef(color, tmp);
		}
		ft_pixel(img, ft_coef_x_color(color, inter.color), index);
	}
	else
		ft_pixel(img, (10 | 10 << 8 | 10 << 16), index);
}
