/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_phong.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:32:30 by adelille          #+#    #+#             */
/*   Updated: 2021/01/29 16:41:16 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_phong		ft_phong(t_ray ray, t_inter inter, t_vector l_pos)
{
	t_vector	H;
	t_vector	viewer_direction;
	t_phong		phong;
	t_vector	l_direction;
	double		prod;

	viewer_direction.x = 0;
	viewer_direction.y = 0;
	viewer_direction.z = 0;
	l_direction.x = 0;
	l_direction.y = 0;
	l_direction.z = 0;
	phong.diffuse = 0;
	phong.specular = 0;
	l_direction = ft_normalize(ft_sub(l_pos, inter.coord));
	phong.diffuse = ft_dot(inter.normal, l_direction);
	phong.diffuse = (phong.diffuse < 0 ? 0 : phong.diffuse);
	viewer_direction = ft_scale(ray.direction, -1);
	H = ft_sub(ft_scale(inter.normal,
		(2 * ft_dot(inter.normal, (l_direction)))), (l_direction));
	prod = ft_dot(H, viewer_direction) / ft_get_norm(viewer_direction) *
		ft_get_norm(viewer_direction);
	if (ft_dot(H, viewer_direction) > 0)
		phong.specular = pow(prod, PHONG_R);
	return (phong);
}
