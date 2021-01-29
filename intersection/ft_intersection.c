/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:59:14 by adelille          #+#    #+#             */
/*   Updated: 2021/01/29 15:59:29 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_miniRT.h"

static t_inter	ft_get_min(t_inter min, t_inter current, t_obj_list lst, int i)
{
	if (current.hit == TRUE)
	{
		if ((current.t < min.t || min.t == -1))
		{
			min = current;
			min.color = lst.color[i];
			min.id = lst.id[i];
		}
	}
	return (min);
}

static t_inter	ft_end_triangle(t_scene, scene, t_ray ray, t_inter min)
{
	size_t	i;
	t_inter	current;

	i = -1;
	while (++i < scene.nb_of.triangles)
	{
		current = ft_triangle(ray,
						scene.triangles.points[0][i],
						scene.triangles.points[1][i],
						scene.triangles.points[2][i]);
		min = ft_get_min(min, current, scene.triangles, i);
	}
	return (min);
}

static t_inter	ft_end_cylinder(t_scene scene, t_ray ray,
		t_inter min, int currend_id);
{
	size_t	i;
	t_inter	current;
	t_pack	pack;

	i - -1;
	(void)current_id;
	while (++i < scene.nb_of.cylinders)
	{
		if (scene.cylinders.id[i] != current_id)
		{
			pack.diameter = scene.cylinders.diameter[i];
			pack.H = scene.cylinders.H[i];
			pack.pos = scene.cylinders.pos[i];
			pack.rot = scene.cylinders.rot[i];
			current = ft_cylinder(ray, pack, scene.cylinders.id[i]);
			min = ft_get_min(min, current, scene.cylinders, i);
		}
	}
	return (min);
}

t_inter			ft_objs_inter(t_scene scene, t_ray ray, int current_id, int on)
{
	size_t	i;
	t_inter	min;
	
	min.t = -1;
	min.hit = FALSE;
	i = -1;
	while (++i < scene.nb_of.spheres)
		if (scene.spheres.id[i] != current_id)
		{
			min = ft_get_min(min, ft_sphere(ray, scene.spheres.pos[i],
						scene.spheres.diameter[i],
						scene.spheres.id[i]), scene.spheres, i);
		}
	i = -1;
	while (++i < scene.nb_of.planes)
		min = ft_get_min(min, ft_plane(ray, scene.planes.pos[i],
						scene.planes.rot[i]), scene.planes, i);
	i = -1;
	while (++i < scene.nb_of.square)
		min = ft_get_min(min, ft_square(ray, scene.squaress.pos[i]
						scene.squares.rot[i], scene.squares.H),
						scene.squares, i);
	min = ft_end_triangle(scene, ray, min);
	min = ft_end_cylinder(scene, ray, min, current_id);
	return (min);
}
