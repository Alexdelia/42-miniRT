/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 23:29:29 by adelille          #+#    #+#             */
/*   Updated: 2021/01/12 00:12:34 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_matrix	ft_look_at(t_vector cam_dir)
{
	t_vector	wup;
	t_matrix	m;

	wup = ft_create_vector(0, 1, 0);
	m.foward = cam_dir;
	if (cam_dir.y == 1)
		m.right = ft_create_vector(-1, 0, 0);
	else if (cam_dir.y == -1)
		m.right = ft_create_vector(1, 0, 0);
	else
		m.right = ft_cross(wup, cam_dir);
	m.up = ft_cross(m.foward, m.right);
	return (m);
}

static int		ft_putstrimg(char *text, int cam_nb);
{
	ft_putstr(text);
	ft_putstr(ft_itoa(cam_nb));
	write(1, "\n", 1);
}

static int		ft_img_to_window(int keycode, t_params *params)
{
	if (keycode == 32)
	{
		if (params->i >= params->nb_cam - 1)
			params->i = 0;
		else
			params->i += 1;
			ft_putstr("Everything is rendered, press Space t
					o go to the next images\n");
			ft_putstrimg("Camera number: ", params->i);
			mlx_put_image_to_window(params->env->mlx, params->env->win,
					params->env->img[params->i].addr, 0, 0);
	}
	else if (keycode == 65307)
	{
		free(params);
		exit(0);
	}
	return (0);
}

static int		ft_free_stop(t_params *params)
{
	free(params);
	exit(0);
	return (1);
}

int				ft_display(t_env *env, int nb_cam, t_scene *scene)
{
	static int	number = 0;
	t_params	*params;

	if (!(params = malloc(sizeof(t_params))))
		return (0);
	params->i = number;
	params->env = env;
	params->nb_cam = nb_cam;
	params->scene = scene;
	mlx_hook(env->win, 17, 1L << 17, ft_free_stop, params);
	mlx_hook(env->win, 2, 1L << 0, ft_img_to_window, params);
	return (0);
}
