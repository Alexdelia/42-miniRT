/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_math1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <adelille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 02:36:08 by user42            #+#    #+#             */
/*   Updated: 2021/02/03 17:14:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	ft_create_vector(double x, double y, double z)
{
	t_vector	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

double		ft_dot(t_vector a, t_vector b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double		ft_get_norm(t_vector a)
{
	return (sqrt(ft_dot(a, a)));
}

t_vector	ft_normalize(t_vector a)
{
	t_vector	res;
	double		norm;

	norm = ft_get_norm(a);
	res.x = a.x / norm;
	res.y = a.y / norm;
	res.z = a.z / norm;
	return (res);
}
