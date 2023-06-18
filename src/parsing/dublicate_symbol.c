/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dublicate_symbol.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:06:52 by manykhac          #+#    #+#             */
/*   Updated: 2023/06/17 17:38:24 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	dublicte_symbol(char **g_map, int i, int index)
{
	int	j;
	int	flag;

	j = 0;
	flag = 0;
	while (i <= index)
	{
		j = 0;
		while (g_map[i][j])
		{
			if (g_map[i][j] == 'S' || g_map[i][j] == 'W' || g_map[i][j] == 'E'
				|| g_map[i][j] == 'N')
				flag++;
		j++;
		}
		i++;
	}
	if (flag != 1)
	{
		printf("Dublicte symbols in map or player does not exist\n");
		return (1);
	}
	return (0);
}

int	check_valid_map(char **g_map, int i, int index)
{
	int	j;

	j = 0;
	while (i <= index)
	{
		j = 0;
		while (g_map[i][j])
		{
			if (g_map[i][j] != '0' && g_map[i][j] != '1'
			&& g_map[i][j] != 'S' && g_map[i][j] != 'W' && g_map[i][j] != 'E'
			&& g_map[i][j] != 'N' && g_map[i][j] != '\n' && g_map[i][j] != ' ')
			{
				printf("Other character in map\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
