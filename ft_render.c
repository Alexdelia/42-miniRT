/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 09:03:43 by adelille          #+#    #+#             */
/*   Updated: 2021/01/06 23:21:32 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_miniRT.h"

static t_inter	ft_get_min(t_inter min, t_inter current, t_obj_list lst, int i)
{
	if (current.hit == TRUE)
	{
		if ((current.t < min.t || min.t == -1))
		{
			min = current;
			min.color = lst.color[i];
			min.id = lst.id[i];
		}
	}
	return (min);
}

t_inter			ft_objs_inter(t_scene scene, t_ray ray, int current_id, int on)
{
	size_t	i;
	t_inter	min;
	t_inter	current;
	
	min.t = -1;
	min.hit = FALSE;
	i = -1;
	while (++i < scene.nb_of.spheres)
	{
		if (scene.spheres.id[i] != current_id || on == 0)
		{
			current = ft_sphere(ray, scene.spheres.pos[i],
						scene.sphere.diameter[i], scene.spheres.id[i]);
			min = ft_get_min(min, current, scene.spheres, i);
		}
	}
	i = -1;
	while (++i < scene.nb_of.planes)
	{
		current = ft_planes();
		min = ft_get_min(min, current, scene.planes, i);
	}
	i = -1;
	while (++i < scene.nb_of.triangles)
	{
		// this one might need the coord of each point in arg
		current = ft_triangle();
		min = ft_get_min(min, current, scene.triangles, i);
	}
	i = -1;
	while (++i < scene.nb_of.squares)
	{
		current = ft_square();
		min = ft_get_min(min, current, scene.square, i);
	}
	i = -1;
	while (++i < scene.nb_of.cylinders)
	{
		// this one might need a struct to handle all arg
		current = ft_cylinders();
		min = ft_get_min(min, current, scene.cylindes, i);
	}
	return (min);
}

static t_vector	ft_get_pixel_pos(t_scene scene, int x, int y, t_camera camera)
{
	t_vector	pixel;
	double		scale;
	t_vector	tmp;
	scale = tan(camera.fov / 2);
	pixel.x = (2 * (x + 0.5) / (double)scene.x - 1)
				* scene.aspect_ratio * scale;
	pixel.y = (1 - 2 * (y + 0.5) / (double)scene.y) * scale;
	tmp = pixel;
	pixel.x = ft_dot(tmp, camera.rotation_matrix.right);
	pixel.y = ft_dot(tmp, camera.rotation_matrix.up);
	pixel.z = ft_dot(tmp, camera.rotation_matrix.foward);
	return (pixel);
}

static void		ft_raycast(t_scene scene, t_env *env, t_camera camera, size_t i)
{
	int		x;
	int		y;
	size_t	index;
	t_inter	inter;
	t_inter	inter_light;
	t_ray	ray;
	t_ray	ray_light;

	y = 0;
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
	env->img[i].buffer[y * x * 4] = '\0';
}

int			ft_render_call(t_pixel *pixels, t_scene *scene)
{
	size_t			i;
	t_camera		camera;

	camera.fov = scene.cameras.fov[i];
	i = 0;
	while (i < scene.nb_of.cameras)
	{
		ft_raycast(scene, &env, camera, i);
		i++;
	}
	return (0);
}
