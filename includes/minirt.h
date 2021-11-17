/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <adelille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:12:12 by user42            #+#    #+#             */
/*   Updated: 2021/11/17 16:05:42 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include "struct_def.h"

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <limits.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0
# define MALLOC -1
# define PHONG_R 80

# define OPEN_MAX 256
# define BUFFER_SIZE 2048

int			ft_check_scene(t_scene scene);
int			ft_parse(char *file, t_scene *scene);
int			ft_init_scene_list(t_scene *scene);
int			ft_find(char *str, char *id);
int			ft_check_only_letter(char *line);

int			ft_parse_line(char *line, t_scene *scene);
void		ft_exit_parser(int nb_lines, char **scene_lines,
				int i, t_scene *scene);

int			ft_render(t_scene scene, t_env *env);
void		ft_render_pixel(t_scene scene, t_img *img, t_ray ray, int index);
t_inter		ft_objs_inter(t_scene scene, t_ray ray, int current_id);
t_phong		ft_phong(t_ray ray, t_inter inter, t_vector l_pos);
t_matrix	ft_look_at(t_vector cam_dir);

int			ft_save_bmp(int ac, char **av, t_scene *scene, t_env *env);

int			ft_display(t_env *env, int nb_cam, t_scene *scene);

int			ft_error(char *text, int type);
int			ft_exit(char *text);
int			ft_free_exit(t_params *params);
int			ft_strcmp(char *str, char *cmp);
double		ft_atof(char *str);

void		ft_free_scene(t_scene *scene);
int			ft_free_s(char *error, t_scene *scene);
void		ft_free(t_scene *scene);

void		ft_get_normal(t_ray ray, t_vector obj_pos, t_inter *inter);
t_inter		ft_sphere(t_ray ray, t_vector pos, double diameter, int id);
t_inter		ft_plane(t_ray ray, t_vector point, t_vector normal);
t_inter		ft_square(t_ray ray, t_vector pos, t_vector rot, double ht);
t_inter		ft_triangle(t_ray ray, t_vector a, t_vector b, t_vector c);
t_inter		ft_cylinder(t_ray ray, t_pack cylinder, int id);

int			ft_isnum(char **line);
int			ft_while_num(char **line);
int			ft_iscomma_inc(char **line);
int			ft_while_num_or_neg(char **line);
int			ft_isnum_neg(char **line);
int			ft_while_wspace(char **line);
int			ft_parse_line_ret(char *line);
int			ft_get_rgba(char **line);
int			ft_get_vect(char **line, int is_unit, t_vector *a);
int			ft_atoi_error(char **str, int *nb);
int			ft_get_resolution(char **line, t_scene *scene);
int			ft_get_ambient_light(char *line, t_scene *scene);
int			ft_get_light(char *line, t_scene *scene);
int			ft_get_camera(char *line, t_scene *scene);
int			ft_get_obj(char *line, t_scene *scene, int type, int id);
int			ft_get_pos(char **line, t_obj *obj);
int			ft_get_rot(char **line, t_obj *obj);
int			ft_get_diam(char **line, t_obj *obj);
int			ft_get_height(char **line, t_obj *obj);

int			adjust_int(int color);
void		adjust_array(double *rgb);
int			ft_coef_x_color(t_color rgb, int color);
void		ft_add_coef(t_color *rgb, double ratio, int color, t_phong phong);
t_color		ft_coef_p_coef(t_color a, t_color b);

t_vector	ft_create_vector(double x, double y, double z);
double		ft_dot(t_vector a, t_vector b);
double		ft_get_norm(t_vector a);
t_vector	ft_normalize(t_vector a);
t_vector	ft_add(t_vector a, t_vector b);
t_vector	ft_sub(t_vector a, t_vector b);
t_vector	ft_multiply(t_vector a, t_vector b);
t_vector	ft_cross(t_vector a, t_vector b);
t_vector	ft_scale(t_vector a, double b);
double		ft_max(double a, double b);
double		ft_min(double a, double b);

int			get_next_line(int fd, char **line);
char		*gnl_ft_strjoin(char *s1, char *s2);

#endif
