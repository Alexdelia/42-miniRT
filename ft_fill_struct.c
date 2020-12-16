/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 02:05:32 by adelille          #+#    #+#             */
/*   Updated: 2020/12/16 03:10:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_miniRT.h"

t_ray		ft_fill_ray(double x, double y, double z, vector direction)
{
	t_ray		ray;
	
	/*if (!(ray = malloc(sizeof(t_ra))))
	{
		ft_error("", -1);
		return (NULL);
	}*/
	ray.origin[0] = x;
	ray.origin[1] = y;
	ray.origin[2] = z;
	ray.direction[0] = direction[0];
	ray.direction[1] = direction[1];
	ray.direction[2] = direction[2];
	return (ray);
}

t_sphere	ft_fill_sphere(double x, double y, double z, double diameter)
{
	t_sphere	sphere;

	/*if (!(sphere = malloc(sizeof(t_sphere))))
	{
		ft_error("", -1);
		return (NULL);
	}*/
	sphere.origin[0] = x;
	sphere.origin[1] = y;
	sphere.origin[2] = z;
	sphere.diameter = diameter;
	return (sphere);
}
