/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_def.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 01:43:00 by adelille          #+#    #+#             */
/*   Updated: 2020/12/16 02:32:33 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_DEF_H
# define STRUCT_DEF_H

typedef double	vector[3];

typedef struct		s_ray
{
	vector			origin;
	vector			direction;
}					t_ray;
t_ray				ft_fill_ray(double x, double y,
							double z, vector direction);

typedef struct		s_sphere
{
	vector			origin;
	double			diameter;
	int				color;
}					t_sphere;
t_sphere			ft_fill_sphere(double x, double y,
							double z, double diameter);

#endif
