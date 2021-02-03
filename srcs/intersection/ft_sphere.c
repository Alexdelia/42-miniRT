/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:14:06 by adelille          #+#    #+#             */
/*   Updated: 2021/02/03 17:20:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int		ft_get_distance(t_delta delta, t_inter *inter)
{
	double t1;
	double t2;

	t1 = (-delta.b - sqrt(delta.delta)) / (2 * delta.a);
	t2 = (-delta.b + sqrt(delta.delta)) / (2 * delta.a);
	if (t2 < 0)
		return (0);
	inter->t = (t1 > 0 ? t1 : t2);
	return (1);
}

void			ft_get_normal(t_ray ray, t_vector obj_pos, t_inter *inter)
{
	ray.direction.x *= inter->t;
	ray.direction.y *= inter->t;
	ray.direction.z *= inter->t;
	inter->coord = ft_add(ray.origin, ray.direction);
	inter->normal = ft_normalize(ft_sub(inter->coord, obj_pos));
}

inline t_inter	ft_sphere(t_ray ray, t_vector pos, double diameter, int id)
{
	t_delta		delta;
	t_inter		inter;

	inter.type = SPHERE;
	inter.id = id;
	delta.a = pow(ft_get_norm(ray.direction), 2);
	delta.b = 2 * ft_dot(ray.direction, ft_sub(ray.origin, pos));
	delta.c = pow(ft_get_norm(ft_sub(ray.origin, pos)), 2)
			- pow(diameter / 2, 2);
	delta.delta = pow(delta.b, 2) - 4 * delta.a * delta.c;
	inter.hit = FALSE;
	if (delta.delta < 0)
		return (inter);
	if (ft_get_distance(delta, &inter) == 0)
		return (inter);
	inter.hit = TRUE;
	ft_get_normal(ray, pos, &inter);
	if (ft_dot(inter.normal, ray.direction) > 0)
		inter.normal = ft_scale(inter.normal, -1);
	return (inter);
}
