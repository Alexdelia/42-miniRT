/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:06:33 by adelille          #+#    #+#             */
/*   Updated: 2021/01/22 22:42:22 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_miniRT.h"

int			ft_init_env(t_scene *scene, t_env *env)
{
	int	x;
	int	y;

	env->mlx = mlx_init();
	if (save)
	{
		mlx_get_screen_size(env->mlx, &x, &y);
		env->size_x = (scene->x > x ? x : scene->x);
		env->size_y = (scene->y > y ? y : scene->y);
	}
	else
	{
		env->size_x = scene->x;
		env->size_y = scene->y;
	}
	scene->x = env->size_x;
	scene->y = env->size_y;
	scene->aspect_ratio = (double)scene->x / (double)scene->y;
	//env->win = mlx_new_window(env->mlx, env->size_x, env->size_y, "miniRT");
	if (!(env->img = malloc(sizeof(t_img) * scene->nb_of.cameras)))
		return (-1);
	return (0);
}

int			main(int ac, char **av)
{
	t_scene	scene;
	t_env	env;
	int		save;

	ft_init_scene(&scene);
	save = 1;
	if (av[2])
		save = ft_strcmp(av[2], "--save");
	if (ac == 2 || (ac == 3 && save == 0))
		ft_parse(av[1], &scene);
	else
		ft_exit("Error: wrong input\n");
	ft_check_scene(scene);
	ft_init_env(&scene, &env, save);
	ft_render(scene, &env);
	ft_save_bmp(ac, av, &scene, &env);
	ft_display(&env, scene.nb_of.cameras, &scene);
	ft_free(&scene);
	mlx_loop(env.mlx);
	return (0);
}
