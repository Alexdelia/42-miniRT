/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:52:45 by adelille          #+#    #+#             */
/*   Updated: 2021/01/29 15:40:11 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_inter	ft_square(t_ray ray, t_vector pos, t_vector rot, double H)
{
	t_inter		inter;
	t_vector	ab;

	inter = ft_plane(ray, pos, rot);
	H /= 2;
	if (inter.hit == TRUE)
	{
		inter.hit = FALSE;
		ab = ft_sub(inter.coord, pos);
		if (fabs(ab.x) <= H &&
					fabs(ab.y) <= H &&
					fabs(ab.z) <= H)
			inter.hit = TRUE;
	}
	return (inter);
}
