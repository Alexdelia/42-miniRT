/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_init_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:17:24 by adelille          #+#    #+#             */
/*   Updated: 2021/02/01 11:12:44 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int			ft_parse_line(char *line, t_scene *scene)
{
	static int	id = 0;

	id++;
	if (ft_find(line, "R"))
		return (ft_get_resolution(&line, scene));
	else if (ft_find(line, "A"))
		return (ft_get_ambient_light(line, scene));
	else if (ft_find(line, "c"))
		return (ft_get_camera(line, scene));
	else if (ft_find(line, "l"))
		return (ft_get_light(line, scene));
	else if (ft_find(line, "sp"))
		return (ft_get_obj(line, scene, 2, id));
	else if (ft_find(line, "pl"))
		return (ft_get_obj(line, scene, 3, id));
	else if (ft_find(line, "sq"))
		return (ft_get_obj(line, scene, 4, id));
	else if (ft_find(line, "cy"))
		return (ft_get_obj(line, scene, 5, id));
	else if (ft_find(line, "tr"))
		return (ft_get_obj(line, scene, 6, id));
	return (ft_parse_line_ret(line));
}

static int	ft_init_obj_list(t_obj_list *lst, int n, int type)
{
	if (!(lst->id = malloc(sizeof(int) * n)) ||
			!(lst->type = malloc(sizeof(int) * n)))
		return (0);
	if (type != 6)
		if (!(lst->pos = malloc(sizeof(t_vector) * n)))
			return (0);
	if (type != 2 && type != 6)
		if (!(lst->rot = malloc(sizeof(t_vector) * n)))
			return (0);
	if (type == 2 || type == 5)
		if (!(lst->diameter = malloc(sizeof(double) * n)))
			return (0);
	if (type == 4 || type == 5)
		if (!(lst->H = malloc(sizeof(double) * n)))
			return (0);
	if (type == 6)
	{
		lst->points[0] = malloc(sizeof(t_vector) * n);
		lst->points[1] = malloc(sizeof(t_vector) * n);
		lst->points[2] = malloc(sizeof(t_vector) * n);
		if (lst->points[0] == NULL || lst->points[1] == NULL ||
				lst->points[2] == NULL)
			return (0);
	}
	return ((lst->color = malloc(sizeof(int) * n)) == NULL ? 0 : 1);
}

static int	ft_init_cam_list(t_camera_list *list, int n)
{
	if (!(list->id = malloc(sizeof(int) * n)))
		return (0);
	if (!(list->fov = malloc(sizeof(double) * n)))
		return (0);
	if (!(list->rot = malloc(sizeof(t_vector) * n)))
		return (0);
	if (!(list->pos = malloc(sizeof(t_vector) * n)))
		return (0);
	return (1);
}

static int	ft_init_light_list(t_light_list *list, int n)
{
	if (!(list->id = malloc(sizeof(int) * n)))
		return (0);
	if (!(list->colors = malloc(sizeof(int) * n)))
		return (0);
	if (!(list->ratio = malloc(sizeof(double) * n)))
		return (0);
	if (!(list->pos = malloc(sizeof(t_vector) * n)))
		return (0);
	if (!(list->dir = malloc(sizeof(t_vector) * n)))
		return (0);
	if (!(list->distance = malloc(sizeof(double) * n)))
		return (0);
	return (1);
}

int		ft_init_scene_list(t_scene *scene)
{
	(void)scene;
	if (!ft_init_light_list(&scene->lights, scene->nb_of.lights))
		ft_putstr_fd("light error\n", 1);
	if (!ft_init_cam_list(&scene->cameras, scene->nb_of.cameras))
		ft_putstr_fd("cam error\n", 1);
	if (!ft_init_obj_list(&scene->spheres, scene->nb_of.spheres, 2))
		ft_putstr_fd("sphere error\n", 1);
	if (!ft_init_obj_list(&scene->planes, scene->nb_of.planes, 3))
		ft_putstr_fd("plane error\n", 1);
	if (!ft_init_obj_list(&scene->squares, scene->nb_of.squares, 4))
		ft_putstr_fd("square error\n", 1);
	if (!ft_init_obj_list(&scene->cylinders, scene->nb_of.cylinders, 5))
		ft_putstr_fd("cylinder error\n", 1);
	if (!ft_init_obj_list(&scene->triangles, scene->nb_of.triangles, 6))
		ft_putstr_fd("triangle error\n", 1);
	return (1);
}
