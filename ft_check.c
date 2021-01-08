/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 07:24:02 by adelille          #+#    #+#             */
/*   Updated: 2021/01/08 07:44:40 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_check_unit(double nb)
{
	if (nb > 1.0 || nb < 0.0)
		return (0);
	return (1);
}

static int	ft_check_rgb(int rgb)
{
	if ((rgb & 0xFF) > 255 || (rgb & 0xFF) < 0)
		return (0);
	if ((rgb >> 8 & 0xFF) > 255 || (rgb >> 8 & 0xFF) < 0)
		return (0);
	if ((rgb >> 16 & 0xFF) > 255 || (rgb >> 16 & 0xFF) < 0)
		return (0);
	return (1);
}

int			ft_check_scene(t_scene scene)
{
	if (scene.y <= 0 || scene.x <= 0)
		ft_exit("Error: Screen resolution can't be <= 0\n");
	if (!scene.ambient_light_ratio && !scene.ambient_light_rgb)
		ft_exit("Error: No ambient light\n");
	if (!ft_check_unit(scene.ambient_light_ratio))
		ft_exit("Error: Ambient light is > 1.0 or < 0.0\n");
	if (scene.nb_of.cameras <= 0)
		ft_exit("Error: No camera\n");
	return (0);
}
