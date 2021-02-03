/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 02:05:32 by adelille          #+#    #+#             */
/*   Updated: 2021/02/03 17:13:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	scene->nb_of.squares = 0;
	scene->ambient_light_ratio = -1;
	scene->ambient_light_rgb = -1;
}
