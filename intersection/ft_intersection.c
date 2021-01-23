/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersection.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 17:59:14 by adelille          #+#    #+#             */
/*   Updated: 2021/01/23 18:58:28 by adelille         ###   ########.fr       */
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
	i = -1;
	while (++i < scene.nb_of.cylinders)
	{
		// this one might need a struct to handle all arg
		current = ft_cylinders();
		min = ft_get_min(min, current, scene.cylindes, i);
	}
	return (min);
}
