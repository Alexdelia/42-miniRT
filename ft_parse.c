/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 06:23:29 by adelille          #+#    #+#             */
/*   Updated: 2020/12/15 11:17:36 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_miniRT.h"

static int	ft_intersection(ray, sphere)
{
	/*double	a;
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
		return (1);*/
	return (0);

}

int			ft_fill_pixels(t_pixel *pixels, int H, int W)
{
	int	i;

	i = -1;
	while (++i <= H * W)
	{
		if (ft_intersection(ray, sphere))
		{
			pixels[i].R = 255;
			pixels[i].G = 255;
			pixels[i].B = 255;
		}
	}
}
