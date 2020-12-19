/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/19 17:14:06 by adelille          #+#    #+#             */
/*   Updated: 2020/12/19 17:38:21 by adelille         ###   ########.fr       */
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
	if (t1 > 0)
		inter->t = t1;
	else
		inter->t = t2;
	return (1);
}

static void		ft_get_normal(t_ray ray, t_vector obj_pos, t_inter *inter)
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

	inter.type = sphere;
	inter.id = id;
	delta.a = SQ(ft_get_norm(ray.direction));
	delta.b = 2 * ft_dot(ray.origin, pos) - SQ(diameter / 2);
	delta.delta = SQ(delta.b) - 4 * delta.a * delta.c;

	inter.hit = FALSE;
	if (delta.delta < 0)
		return (inter);
	inter.hit = TRUE;
	if (ft_get_distance(delta, &inter) == 0)
		inter.hit = FALSE;
	ft_get_normal(ray, pos, &inter);
	if (dot(inter.normal, ray.direction) > 0)
	{
			inter.normal = ft_multiply(inter.normal,
			ft_create_vector(-1, -1, -1));
	}
	return (inter);
}
