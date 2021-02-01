/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:03:43 by adelille          #+#    #+#             */
/*   Updated: 2021/02/01 11:13:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static t_vector	ft_get_pixel_pos(t_scene scene, int x, int y, t_camera camera)
{
	t_vector	pixel;
	double		scale;
	t_vector	tmp;
	t_vector	rot_vector[3];

	scale = tan(camera.fov / 2);
	pixel.x = (2 * (x + 0.5) / (double)scene.x - 1)
				* scene.aspect_ratio * scale;
	pixel.y = (1 - 2 * (y + 0.5) / (double)scene.y) * scale;
	pixel.z = 1;
	tmp = pixel;
	rot_vector[0] = ft_create_vector(camera.rotation_matrix.right.x,
			camera.rotation_matrix.up.x, camera.rotation_matrix.foward.x);
	rot_vector[1] = ft_create_vector(camera.rotation_matrix.right.y,
			camera.rotation_matrix.up.y, camera.rotation_matrix.foward.y);
	rot_vector[2] = ft_create_vector(camera.rotation_matrix.right.z,
			camera.rotation_matrix.up.z, camera.rotation_matrix.foward.z);
	pixel.x = ft_dot(tmp, rot_vector[0]);
	pixel.y = ft_dot(tmp, rot_vector[1]);
	pixel.z = ft_dot(tmp, rot_vector[2]);
	return (pixel);
}

static void		ft_raycast(t_scene scene, t_env *env, t_camera camera, size_t i)
{
	int		x;
	int		y;
	size_t	index;
	t_ray	ray;

	y = 0;
	index = 0;
	ray.origin = camera.pos;
	while (y < scene.y)
	{
		x = 0;
		while (x < scene.x)
		{
			ray.direction = ft_normalize(ft_get_pixel_pos(scene, x, y, camera));
			ft_render_pixel(scene, &env->img[i], ray, index);
			index += 4;
			x++;
		}
		y++;
	}
}

int			ft_render(t_scene scene, t_env *env)
{
	size_t			i;
	t_camera		camera;

	i = 0;
	while (i < scene.nb_of.cameras)
	{
		env->img[i].addr = mlx_new_image(env->mlx, env->size_x, env->size_y);
		env->img[i].buffer = mlx_get_data_addr(env->img[i].addr,
				&env->img[i].bpp, &env->img[i].line_size, &env->img[i].endian);
		camera.pos = scene.cameras.pos[i];
		camera.rot = scene.cameras.rot[i];
		camera.fov = scene.cameras.fov[i];
		camera.rotation_matrix = ft_look_at(camera.rot);
		ft_raycast(scene, env, camera, i);
		i++;
	}
	return (0);
}
