/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <adelille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 22:31:43 by user42            #+#    #+#             */
/*   Updated: 2020/12/21 09:30:12 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_miniRT.h"

int	ft_error(char *text, int type)
{
	if (type == 0)
		ft_putstr_fd(text, 1);
	else if (type == MALLOC)
	{
		ft_putstr_fd("malloc error", 1);
		ft_putstr_fd("miniRT stop and free all the allocated memories", 1);
	}
	return (-1);
}
