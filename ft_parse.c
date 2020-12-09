/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 06:23:29 by adelille          #+#    #+#             */
/*   Updated: 2020/12/09 07:45:45 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_miniRT.h"

int	ft_parse(scene, camera, ...)
{
	int		iH;
	int		jW;

	iH = 0;
	jW = 0;
	// going pixel per pixel
	while (iH <= H)
	{
		while (jW <= W)
		{
			if (is_intersection(ft_create_ray(camera, iH, jW /*direction*/), form))
				pixel[iH, jW] = white;
			else
				pixel[iH, jW] = black;
			jW++;
		}
		iH++;
	}
}
