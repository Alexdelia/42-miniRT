/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:41:51 by adelille          #+#    #+#             */
/*   Updated: 2021/01/18 10:41:56 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt.h"

int		ft_isnum(char **line)
{
	if ((**line < '0' || **line > '9'))
		return (0);
	return (1);
}

int		ft_while_num(char **line)
{
	while ((**line >= '0' && **line <= '9'))
		*line += 1;
	return (1);
}

int		ft_iscomma_inc(char **line)
{
	if (**line != ',')
		return (0);
	*line += 1;
	return (1);
}

int		ft_while_num_or_neg(char **line)
{
	int i;

	i = 0;
	while ((**line >= '0' && **line <= '9') || **line == '-' || **line == '.')
	{
		if (**line == '-')
		{
			if (*(*line + 1) < '0' || *(*line + 1) > '9')
				return (0);
			if (i == 0)
				i++;
			else
				return (0);
		}
		*line += 1;
	}
	return (1);
}

int		ft_isnum_neg(char **line)
{
	if ((**line < '0' || **line > '9') && **line != '-')
		return (0);
	return (1);
}