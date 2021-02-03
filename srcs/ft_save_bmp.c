/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_bmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 07:15:58 by adelille          #+#    #+#             */
/*   Updated: 2021/02/03 17:14:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		ft_init_header(t_header *header, t_scene scene)
{
	header->bmp_letters[0] = 'B';
	header->bmp_letters[1] = 'M';
	header->file_size = 54 + (scene.x * scene.y * 4);
	header->reserved_bytes = 0;
	header->buffer_offset = 54;
}

static void		ft_init_info(t_info *info, t_scene scene)
{
	info->info_size = 40;
	info->W = scene.x;
	info->H = -scene.y;
	info->color_planes = 1;
	info->color_depth = 32;
	info->compression_method = 0;
	info->raw_data_size = scene.x * scene.y * 4;
	info->horizontal_res = 3780;
	info->vertical_res = 3780;
	info->color_table_entries = 0;
	info->important_colors = 0;
}

static char		*ft_locate(char *name)
{
	int		i;
	int		y;
	char	*file_name;
	char	*tmp;

	i = 0;
	y = 0;
	while (name[i++])
		if (name[i] == '/')
			y = i + 1;
	file_name = ft_strdup(&name[y]);
	tmp = ft_strjoin(file_name, ".bmp");
	free(file_name);
	file_name = ft_strjoin("./output/", tmp);
	free(tmp);
	return (file_name);
}

static void		ft_exit_save(t_scene *scene, t_env *env)
{
	size_t	i;

	i = 0;
	while (i < scene->nb_of.cameras)
	{
		mlx_destroy_image(env->mlx, env->img[i].addr);
		i++;
	}
	mlx_destroy_display(env->mlx);
	ft_free_scene(scene);
	free(env->img);
	free(env->mlx);
	exit(0);
}

int				ft_save_bmp(int ac, char **av, t_scene *scene, t_env *env)
{
	t_header	header;
	t_info		info;
	int			fd;
	char		*file_name;

	ft_init_header(&header, *scene);
	ft_init_info(&info, *scene);
	file_name = NULL;
	if (ac == 3 && ft_strcmp(av[2], "--save") == 0)
	{
		printf("Creating %s .bmp\n", file_name);
		file_name = ft_locate(av[1]);
		fd = open(file_name, O_WRONLY | O_TRUNC | O_CREAT, 0775);
		if (fd < 0)
			return (ft_error("Failed to open|create .bmp\n", 0));
		write(fd, &header.bmp_letters[0], 2);
		write(fd, &header.file_size, 4);
		write(fd, &header.reserved_bytes, 4);
		write(fd, &header.buffer_offset, 4);
		write(fd, (char *)&info, 40);
		write(fd, &env->img->buffer[0], scene->x * scene->y * 4);
		free(file_name);
		ft_exit_save(scene, env);
	}
	return (0);
}
