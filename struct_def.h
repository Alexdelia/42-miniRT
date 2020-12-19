/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_def.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 01:43:00 by adelille          #+#    #+#             */
/*   Updated: 2020/12/19 17:12:02 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_DEF_H
# define STRUCT_DEF_H

# define SQ(x) x * x

typedef struct		s_inter
{
	double			t;
	t_vector		coord;
	t_vector		normal;
	int				hit;
	int				color;
	double			pixel_intensity;
	int				id;
	int				type;
}					t_inter;

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef struct		s_delta
{
	double			a;
	double			b;
	double			c;
	double			delta;
}					t_delta;

typedef struct		s_ray
{
	t_vector		origin;
	t_vector		direction;
}					t_ray;
t_ray				ft_fill_ray(double x, double y,
							double z, t_vector direction);

typedef struct		s_sphere
{
	t_vector		origin;
	double			diameter;
	int				color;
}					t_sphere;
t_sphere			ft_fill_sphere(double x, double y,
							double z, double diameter);

#endif
