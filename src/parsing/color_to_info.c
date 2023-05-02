/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_to_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:06:13 by manykhac          #+#    #+#             */
/*   Updated: 2023/05/02 12:06:18 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_c_to_info(char **color_map, t_info **info)
{
	int	j;

	j = 0;
	if ((*info)->flag_c_c)
	{
		matrix_free(color_map);
		return (1);
	}
	while (color_map[j])
	{
		(*info)->colors_c[j] = color_map[j];
		j++;
	}
	(*info)->colors_c[j] = NULL;
	(*info)->flag_c_c = 1;
	return (0);
}

int	color_f_to_info(char **color_map, t_info **info)
{
	int	j;

	j = 0;
	if ((*info)->flag_c_f)
	{
		free(color_map);
		return (1);
	}
	while (color_map[j])
	{
		(*info)->colors_f[j] = color_map[j];
		j++;
	}
	(*info)->colors_f[j] = NULL;
	(*info)->flag_c_f = 1;
	return (0);
}

int	color_to_info(char **color_map, t_info **info, char c)
{
	int	j;

	(void)info;
	j = 0;
	if (c == 'F')
	{
		if (color_f_to_info(color_map, info))
			return (1);
	}
	else if (c == 'C')
	{
		if (color_c_to_info(color_map, info))
			return (1);
	}
	free(color_map);
	return (0);
}
