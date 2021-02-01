/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <adelille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 22:31:43 by user42            #+#    #+#             */
/*   Updated: 2021/02/01 11:40:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		ft_error(char *text, int type)
{
	if (type == 0)
		ft_putstr_fd(text, 2);
	else if (type == MALLOC)
	{
		ft_putstr_fd("Malloc error\n", 2);
		ft_putstr_fd("miniRT stop and free all the allocated memories\n", 2);
	}
	return (-1);
}

int		ft_exit(char *text)
{
	ft_putstr_fd(text, 1);
	exit(1);
}

int		ft_free_exit(t_params *params)
{
	int	i;

	i = 0;
	while (i < params->nb_cam)
	{
		mlx_destroy_image(params->env->mlx, params->env->img[i].addr);
		i++;
	}
	mlx_destroy_window(params->env->mlx, params->env->win);
	mlx_destroy_display(params->env->mlx);
	free(params->env->img);
	free(params->env->mlx);
	free(params);
	exit(0);
	return (1);
}

int		ft_strcmp(char *str, char *cmp)
{
	int	i;

	i = 0;
	while (str[i] && cmp[i])
	{
		if (!(str[i] == cmp[i]))
			return (0);
		i++;
	}
	return (1);
}

double	ft_atof(char *str)
{
	double	res;
	double	neg;
	double	divider;
	size_t	i;

	divider = 0.1;
	res = 0;
	neg = 1;
	i = -1;
	while (str[i] < '0' || str[i] > '9')
		if (str[i++] == '-')
			neg = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - 48;
	}
	if (str[i] == '.')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res + (str[i] - 48) * divider;
		divider /= 10;
		i++;
	}
	return (res * neg);
}
