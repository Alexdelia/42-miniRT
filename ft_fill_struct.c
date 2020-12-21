/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 02:05:32 by adelille          #+#    #+#             */
/*   Updated: 2020/12/21 08:24:56 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_miniRT.h"

t_ray		ft_fill_ray(double x, double y, double z, vector direction)
{
	t_ray		ray;
	
	ray.origin[0] = x;
	ray.origin[1] = y;
	ray.origin[2] = z;
	ray.direction[0] = direction[0];
	ray.direction[1] = direction[1];
	ray.direction[2] = direction[2];
	return (ray);
}

void		ft_init_scene(t_scene *scene)
{
	scene->x = 0;
	scene->y = 0;
	scene->nb_of.cameras = 0;
	scene->nb_of.lights = 0;
	scene->nb_of.spheres = 0;
	scene->nb_of.cylinders = 0;
	scene->nb_of.planes = 0;
	scene->nb_of.triangles = 0;
	scene->nb_of.sqaures = 0;
}
