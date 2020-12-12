/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_miniRT.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:02:06 by adelille          #+#    #+#             */
/*   Updated: 2020/12/12 09:17:45 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft/libft.h"
# include "mlx/mlx.h"

# include <fcntl.h>

typedef struct	s_pixel
{
	unsigned char	B;
	unsigned char	G;
	unsigned char	R;
}				t_pixel;

int		ft_save_bmp(t_pixel *pixels, int H, int W);

int		ft_mlx_init(t_pixel *pixels, int H, int W);

int		ft_error(char *text, int type);

#endif
