/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:29:53 by adelille          #+#    #+#             */
/*   Updated: 2021/01/29 15:39:43 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

inline t_inter	ft_plane(t_ray ray, t_vector point, t_vector normal)
{
	t_inter	inter;
	double	a;
	double	b;
	
	inter.type = PLANE;
	inter.hit = FALSE;
	a = ft_dot(ft_sub(ray.origin, point), normal);
	b = ft_dot(ray.direction, normal);
	inter.t = -a / b;
	if (inter.t >= 0)
	{
		ray.direction.x *= inter.t;
		ray.direction.y *= inter.t;
		ray.direction.z *= inter.t;
		inter.coord = ft_add(ray.origin, ray.direction);
		if (b > 0)
			normal = ft_scale(normal, -1);
		inter.normal = ft_normalize(normal);
		inter.hit = TRUE;
	}
	return (inter);
}
