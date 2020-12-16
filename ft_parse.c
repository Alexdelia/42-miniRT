/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 06:23:29 by adelille          #+#    #+#             */
/*   Updated: 2020/12/16 10:11:38 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_miniRT.h"

static int	ft_intersection(t_ray ray, t_sphere sphere)
{
	double	a;
	double	b;
	double	c;
	double	delta;
	double	coord[3];

	coord[0] = ray.origin[0] - sphere.origin[0];
	coord[1] = ray.origin[1] - sphere.origin[1];
	coord[2] = ray.origin[2] - sphere.origin[2];
	a = 1;
	b = 2 * ft_dot(ray.direction, coord);
	c = ft_get_norm2(coord) -
		(sphere.diameter / 2) * (sphere.diameter / 2);
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (0);
	if ((-b + sqrt(delta)) / (2 * a) > 0)
		return (1);
	return (0);

}

int			ft_fill_pixels(t_pixel *pixels)
{
	unsigned int	i;
	double			fov;
	t_sphere		sphere;
	t_ray			ray;
	vector			direction;

	fov = 60 * M_PI / 180;
	i = -1;
	while (++i <= pixels->H * pixels->W)
	{
		direction[0] = (i / pixels->W) - pixels->W / 2;
		direction[1] = (i % pixels->W) - pixels->H / 2;
		direction[2] = (2 * tan(fov / 2));
		/*if (!(sphere = ft_fill_sphere(0, 0, -55, 20)))
			return (-1);
		if (!(ray = ft_fill_ray(0, 0, 0, direction)))
		{
			free(sphere);
			return (-1);
		}*/
		sphere = ft_fill_sphere(0, 0, -55, 10);
		ray = ft_fill_ray(0, 0, 0, direction);
		if (ft_intersection(ray, sphere))
		{
			pixels[i].R = 255;
			pixels[i].G = 255;
			pixels[i].B = 255;
		}
		else
		{
			pixels[i].R = 0;
			pixels[i].G = 0;
			pixels[i].B = 0;
		}
	}
	//free(ray);
	//free(sphere);
	return (0);
}
