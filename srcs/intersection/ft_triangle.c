/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_triangle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 15:32:02 by adelille          #+#    #+#             */
/*   Updated: 2021/02/01 11:25:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int		ft_check_edge(t_vector p, t_vector a,
			t_vector b, t_vector normal)
{
	t_vector	ap;
	t_vector	ab;
	t_vector	c;

	ap = ft_sub(p, a);
	ab = ft_sub(b, a);
	c = ft_cross(ab, ap);
	if (ft_dot(normal, c) < 0)
		return (0);
	return (1);
}

t_inter			ft_triangle(t_ray ray, t_vector a, t_vector b, t_vector c)
{
	t_vector	ab;
	t_vector	ac;
	t_vector	normal;
	t_inter		inter;

	ab = ft_sub(b, a);
	ac = ft_sub(c, a);
	normal = ft_normalize(ft_cross(ab, ac));
	inter = ft_plane(ray, b, normal);
	if (inter.hit == TRUE)
	{
		if (!ft_check_edge(inter.coord, a, b, normal) ||
					!ft_check_edge(inter.coord, b, c, normal) ||
					!ft_check_edge(inter.coord, c, a, normal))
		{
			inter.hit = FALSE;
			return (inter);
		}
	}
	return (inter);
}
