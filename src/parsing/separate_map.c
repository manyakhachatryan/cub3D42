/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:08:40 by manykhac          #+#    #+#             */
/*   Updated: 2023/05/02 12:08:44 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_longest_str(char **gen_map, int i, int index)
{
	int	len;
	int	tmp_len;

	len = 0;
	tmp_len = 0;
	while (i <= index)
	{
		tmp_len = ft_strlen(gen_map[i]);
		if (tmp_len > len)
			len = tmp_len;
	i++;
	}
	return (len);
}

void	separate_map(t_info **info, char **gen_map, int index, int i)
{
	int	long_str;
	int	j;
	int	k;

	k = 0;
	long_str = find_longest_str(gen_map, i, index);
	(*info)->game_map = malloc(sizeof(char *) * (index - i + 2));
	while (i <= index)
	{
		(*info)->game_map[k] = malloc(sizeof(char) * (long_str + 1));
		j = 0;
		while (gen_map[i][j] && gen_map[i][j] != '\n')
		{
			(*info)->game_map[k][j] = gen_map[i][j];
			j++;
		}
		while (j < long_str -1)
		{
			(*info)->game_map[k][j] = 'X';
			j++;
		}
		i++;
		k++;
	}
}
