/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_miniRT.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:02:06 by adelille          #+#    #+#             */
/*   Updated: 2020/12/21 09:29:25 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include "struct_def.h"

# include <fcntl.h>
# include <math.h>

# define TRUE 1
# define FALSE 0
# define MALLOC -1

typedef struct	s_pixel
{
	unsigned int	H;
	unsigned int	W;
	unsigned int	T;
	unsigned int	B;
	unsigned int	G;
	unsigned int	R;
}				t_pixel;

int			ft_render(t_pixel *pixels, char **av);

int			ft_render_call(t_pixel *pixels, t_scene &scene);

int			ft_save_bmp(t_pixel *pixels);

int			ft_mlx_init(t_pixel *pixels);

int			ft_error(char *text, int type);

t_inter		ft_sphere(t_ray ray, t_vector pos, double diameter, int id);

t_vector	ft_create_vector(double x, double y, double z);
double		ft_dot(t_vector a, t_vector b);
double		ft_get_norm(t_vector a);
t_vector	ft_normalize(t_vector a);
t_vector	ft_add(t_vector a, t_vector b);
t_vector	ft_sub(t_vector a, t_vector b);
t_vector	ft_multiply(t_vector a, t_vector b);

#endif
