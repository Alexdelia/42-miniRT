/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <adelille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 22:31:43 by user42            #+#    #+#             */
/*   Updated: 2021/01/08 07:38:48 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_miniRT.h"

int	ft_error(char *text, int type)
{
	if (type == 0)
		ft_putstr_fd(text, 1);
	else if (type == MALLOC)
	{
		ft_putstr_fd("Malloc error\n", 1);
		ft_putstr_fd("miniRT stop and free all the allocated memories\n", 1);
	}
	return (-1);
}

int	ft_exit(char *text)
{
	ft_putstr_fd(text);
	exit(1);
}
