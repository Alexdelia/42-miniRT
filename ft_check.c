/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 07:24:02 by adelille          #+#    #+#             */
/*   Updated: 2021/01/29 15:42:28 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		ft_check_only_letter(char *line)
{
	int i;

	i = 0;
	ft_while_wspace(&line);
	while ((line[i] >= 'a' && line[i] <= 'z') ||
				(line[i] >= 'A' && line[i] <= 'Z'))
		i++;
	while (line[i])
	{
		if ((line[i] >= 'a' && line[i] <= 'z') ||
				(line[i] >= 'A' && line[i] <= 'Z'))
		{
			ft_putstr_fd("Error: wrong input in .rt\n", 1);
			ft_putstr_fd("Found letters in wrong place\n", 1);
			exit(1);
		}
		i++;
	}
	return (1);
}

int		ft_free_s(char *error, t_scene *scene)
{
	ft_free_scene(scene);
	ft_putstr_fd(error, 1);
	exit(1);
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
		ft_free_s("Error: Screen resolution can't be <= 0\n", scene);
	if (!(scene.ambient_light_ratio < 0 || scene.ambient_light_rgb < 0))
		ft_free_s("Error: No ambient light\n");
	if (scene.ambient_light_ratio < 0.0 || scene.ambient_light_ratio > 1.0)
		ft_free_s("Error: Ambient light is < 0.0 or > 1.0\n");
	if (scene.nb_of.cameras <= 0)
		ft_free_s("Error: No camera\n");
	return (0);
}
