/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_math3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <adelille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 17:05:53 by user42            #+#    #+#             */
/*   Updated: 2021/02/03 17:15:05 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector	ft_scale(t_vector a, double b)
{
	a.x *= b;
	a.y *= b;
	a.z *= b;
	return (a);
}

double		ft_max(double a, double b)
{
	return (a > b ? a : b);
}

double		ft_min(double a, double b)
{
	return (a < b ? a : b);
}
