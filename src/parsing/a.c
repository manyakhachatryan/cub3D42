/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <manykhac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:05:14 by manykhac          #+#    #+#             */
/*   Updated: 2023/05/02 12:16:57 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_data	data_collector(t_cub cub)
{
	t_data	data;

	data.map = NULL;
	data.x = -1;
	data.y = -1;
	getter_cub(&data, cub);
	return (data);
	while (data.map[++(data.y)])
	{
		data.x = -1;
		while (data.map[++data.x])
		{
			if (data.map[data.x][data.y] == 'E' || \
			data.map[data.x][data.y] == 'N' \
			|| data.map[data.x][data.y] == 'S' || \
			data.map[data.x][data.y] == 'W')
			{
				data.pos_x = data.x;
				data.pos_y = data.y;
				break ;
			}
		}
	}
	data.x = -1;
	data.y = -1;
}

void	getter_cub(t_data *data, t_cub cub)
{
	int		i;
	char	**map;

	i = -1;
	while (cub.map[++i])
		;
	map = (char **)malloc(sizeof(char *) * (i + 2));
	if (!map)
		return ;
	i = -1;
	while (cub.map[++i])
		map[i] = ft_strdup(cub.map[i]);
	map[i] = 0;
	data->map = map;
}
