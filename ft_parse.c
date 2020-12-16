/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 06:23:29 by adelille          #+#    #+#             */
/*   Updated: 2020/12/16 02:22:48 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_miniRT.h"

static int	ft_intersection(t_ray ray, t_sphere sphere)
{
	double	a;
	double	b;
	double	c;
	double	delta;

	a = 1;
	b = 2 * dot(d.direction, d.origin - s.O);
	c = (d.origin - s.O).getNorm2() - s.R*s.R;
	delta = b * b - 4 * a * c;
	if (delta < 0)
		return (0);
	if ((-b + sqrt(delta)) / (2 * a))
		return (1);
	return (0);

}

int			ft_fill_pixels(t_pixel *pixels)
{
	int			i;
	double		fov;
	t_sphere	sphere;
	t_ray		ray;
	vector		direction;

	fov = 90 * M_PI / 180;
	direction[0] = (i / pixels.W) - pixels.W / 2;
	direction[1] = (i % pixels.W) - pixels.H / 2;
	direction[2] = (2 * tan(fov / 2));
	if (!(sphere = ft_fill_sphere(0, 0, -55, 20)))
		return (-1);
	if (!(ray = ft_fill_ray(0, 0, 0, direction)))
	{
		free(sphere);
		return (-1);
	}
	i = -1;
	while (++i <= pixels.H * pixels.W)
	{
		if (ft_intersection(ray, sphere))
		{
			pixels[i].R = 255;
			pixels[i].G = 255;
			pixels[i].B = 255;
		}
	}
	return (0);
}
