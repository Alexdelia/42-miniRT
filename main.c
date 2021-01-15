/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:06:33 by adelille          #+#    #+#             */
/*   Updated: 2021/01/15 03:42:44 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_miniRT.h"

int			ft_init_env(t_scene *scene, t_env *env)
{
	int	x;
	int	y;

	env->mlx = mlx_init();
	mlx_get_screen_size(env->mlx, &x, &y);
	env->size_x = (scene->x > x ? x : scene->x);
	env->size_y = (scene->y > y ? y : scene->y);
	scene->x = env->size_x;
	scene->y = env->size_y;
	scene->aspect_ratio = (double)scene->x / (double)scene->y;
	//env->win = mlx_new_window(env->mlx, env->size_x, env->size_y, "miniRT");
	if (!(env->img = malloc(sizeof(t_img) * scene->nb_of.cameras)))
		return (-1);
	return (0);
}

// WIP, Moving mlx part
/*
int			ft_render(t_pixel *pixels, char **av)
{
	if (ft_render_call(pixels, &scene) == -1)
		return (ft_error("ray tracing fail for some reason\n", 0));
	if (av[1] == (char *)"-save" || av[2] == (char *)"-save")
		ft_save_bmp(pixels);
	if (av[1] == (char *)"-png" || av[2] == (char *)"-png")
		ft_putstr_fd("the -png fonction hasn't been code yet\n", 0);
		// ft_save_png
	if (!av[1])
	{
		if (ft_mlx_init(pixels) == -1)
			return (ft_error("mlx return -1 for some reason\n", 0));
	}
	return (0);
}
*/
int			main(int ac, char **av)
{
	(void)ac;
	t_scene			scene;
	t_env			env;

	ft_init_scene(&scene);
	if (argv[1])
		ft_parse(av[1], &scene);
	else
	{
		ft_putstr("Error: no input file\n");
		exit(0);
	}
	ft_check_scene(scene);
	ft_init_env(&scene, &env);
	ft_render(scene, &env); //WIP move parse of -save and -png
	// will need to add save function and display function in ft_render (might need to free(scene + env) in ft_render, or main
	ft_save_bmp(ac, av, scene, env);
	ft_display(&env, scene.nb_of.cameras, &scene);
	ft_free(&scene);
	mlx_loop(env.mlx);
	return (0);
}
