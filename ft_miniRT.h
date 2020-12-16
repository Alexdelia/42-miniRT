/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_miniRT.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:02:06 by adelille          #+#    #+#             */
/*   Updated: 2020/12/16 03:16:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include "struct_def.h"

# include <fcntl.h>
# include <math.h>

typedef struct	s_pixel
{
	unsigned int	H;
	unsigned int	W;
	unsigned int	T;
	unsigned int	B;
	unsigned int	G;
	unsigned int	R;
}				t_pixel;

int		ft_render(t_pixel *pixels, char **av);

int		ft_fill_pixels(t_pixel *pixels);

int		ft_save_bmp(t_pixel *pixels);

int		ft_mlx_init(t_pixel *pixels);

int		ft_error(char *text, int type);

double	ft_dot(const vector a, const vector b);
double	ft_get_norm2(const vector a);

#endif
