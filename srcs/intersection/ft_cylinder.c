/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cylinder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:45:05 by adelille          #+#    #+#             */
/*   Updated: 2021/02/01 11:30:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_inter	ft_edge(t_pack cylinder, t_ray ray, t_inter inter)
{
	double a;
	double max;

	ft_get_normal(ray, cylinder.pos, &inter);
	max = sqrt(pow(cylinder.H / 2.0, 2) + pow(cylinder.diameter / 2, 2));
	if (ft_get_norm(ft_sub(inter.coord, cylinder.pos)) > max)
		return (inter);
	a = ft_dot(cylinder.rot, ft_sub(inter.coord, cylinder.pos));
	inter.normal = ft_normalize(ft_sub(inter.coord,
				ft_add(cylinder.pos, ft_scale(cylinder.rot, a))));
	a = ft_dot(ray.direction, inter.normal);
	if (a > 0)
		inter.normal = ft_scale(inter.normal, -1);
	inter.hit = TRUE;
	return (inter);
}

t_inter			ft_cylinder(t_ray ray, t_pack cylinder, int id)
{
	t_inter		inter;
	t_delta		delta;
	t_ray		new_ray;
	t_vector	c_to_o;

	inter.hit = FALSE;
	inter.id = id;
	new_ray.origin = ray.origin;
	cylinder.rot = ft_normalize(cylinder.rot);
	new_ray.direction = ft_cross(ray.direction, cylinder.rot);
	c_to_o = ft_sub(ray.origin, cylinder.pos);
	delta.a = ft_dot(new_ray.direction, new_ray.direction);
	delta.b = 2 * ft_dot(new_ray.direction, ft_cross(c_to_o, cylinder.rot));
	delta.c = ft_dot(ft_cross(c_to_o, cylinder.rot),
			ft_cross(c_to_o, cylinder.rot)) - pow(cylinder.diameter / 2, 2);
	delta.delta = pow(delta.b, 2) - 4 * delta.c * delta.a;
	if (delta.delta < 0)
		return (inter);
	inter.t1 = (-delta.b - sqrt(delta.delta)) / (2 * delta.a);
	inter.t2 = (-delta.b + sqrt(delta.delta)) / (2 * delta.a);
	if (inter.t2 < 0)
		return (inter);
	inter.t = (inter.t1 > 0 ? inter.t1 : inter.t2);
	return (ft_edge(cylinder, ray, inter));
}
