/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_miniRT.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:02:06 by adelille          #+#    #+#             */
/*   Updated: 2021/01/18 10:49:40 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include "struct_def.h"

# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define TRUE 1
# define FALSE 0
# define MALLOC -1

int			ft_parse(char *file, t_scene *scene);
int			ft_init_scene_list(t_scene *scene);
int			ft_find(char *str, char id);
int			ft_check_only_letter(char *line);

int			ft_render(t_scene scene, t_env *env);
void		ft_render_pixel(t_scene scene, t_img *img, t_ray ray, int index);

//int			ft_save_bmp(...);

int			ft_display(t_env *env, int nb_cam, t_scene *scene);

int			ft_error(char *text, int type);
int			ft_exit(char *text);
int			ft_strcmp(char *str, char *cmp);

int			ft_free_s(char *error, t_scene *scene);
void		ft_free(t_scene *scene);

t_inter		ft_sphere(t_ray ray, t_vector pos, double diameter, int id);

t_vector	ft_create_vector(double x, double y, double z);
double		ft_dot(t_vector a, t_vector b);
double		ft_get_norm(t_vector a);
t_vector	ft_normalize(t_vector a);
t_vector	ft_add(t_vector a, t_vector b);
t_vector	ft_sub(t_vector a, t_vector b);
t_vector	ft_multiply(t_vector a, t_vector b);
t_vector	ft_cross(t_vector a, t_vector b);

#endif
