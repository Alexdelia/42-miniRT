/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_math.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <adelille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 02:36:08 by user42            #+#    #+#             */
/*   Updated: 2020/12/16 03:16:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_miniRT.h"

double		ft_dot(const vector a, const vector b)
{
	return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]); 
}

double		ft_get_norm2(const vector a)
{
	return (a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
}
