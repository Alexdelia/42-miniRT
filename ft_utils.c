/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <adelille@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 22:31:43 by user42            #+#    #+#             */
/*   Updated: 2020/12/09 23:33:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_miniRT.h"

int	ft_error(int type)
{
	if (type == -1)
	{
		ft_putstr_fd("malloc error", 1);
		ft_putstr_fd("miniRT stop and free all the allocated memories", 1);
	}
	return (1);
}
