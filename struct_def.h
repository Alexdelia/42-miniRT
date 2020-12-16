/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_def.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 01:43:00 by adelille          #+#    #+#             */
/*   Updated: 2020/12/16 01:50:19 by adelille         ###   ########.fr       */
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

typedef struct		s_sphere
{
	vector			origin;
	double			diameter;
	int				color;
}					t_sphere;
