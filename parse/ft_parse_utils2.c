/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 10:42:44 by adelille          #+#    #+#             */
/*   Updated: 2021/01/29 15:41:48 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		ft_while_wspace(char **line)
{
	while (**line == 32 || (**line >= 8 && **line <= 14))
		*line += 1;
	return (1);
}

void	ft_exit_parser(int nb_lines, char **scene_lines, int i, t_scene *scene)
{
	while (i < nb_lines)
	{
		free(scene_lines[i]);
		i++;
	}
	free(scene_lines);
	ft_free_s("Error: wrong input in .rt\n", scene);
}

int		ft_parse_line_ret(char *line)
{
	while (*line == 32 || (*line >= 8 && *line <= 14))
		line += 1;
	if (*line != 0)
		return (0);
	return (1);
}
