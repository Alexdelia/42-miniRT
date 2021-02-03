/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:52:45 by adelille          #+#    #+#             */
/*   Updated: 2021/02/03 17:20:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_inter	ft_square(t_ray ray, t_vector pos, t_vector rot, double ht)
{
	t_inter		inter;
	t_vector	ab;

	inter = ft_plane(ray, pos, rot);
	ht /= 2;
	if (inter.hit == TRUE)
	{
		inter.hit = FALSE;
		ab = ft_sub(inter.coord, pos);
		if (fabs(ab.x) <= ht &&
					fabs(ab.y) <= ht &&
					fabs(ab.z) <= ht)
			inter.hit = TRUE;
	}
	return (inter);
}
