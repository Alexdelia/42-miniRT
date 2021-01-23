/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:17:04 by adelille          #+#    #+#             */
/*   Updated: 2021/01/23 18:19:04 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_render_pixel(t_scene scene, t_img *img, t_ray ray, int index)
{
	size_t		i;
	t_inter		inter;
	t_color		color;
	t_color		tmp;

	inter = ft_objs_inter(scene, ray, -1);
	i = -1;
}
