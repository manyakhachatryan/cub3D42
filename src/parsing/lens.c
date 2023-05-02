/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lens.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:07:54 by manykhac          #+#    #+#             */
/*   Updated: 2023/05/02 12:07:58 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_map_len2(char *str, int j, int count)
{
	while (str[j])
	{
		if (str[j] == ' ' || str[j] == '\t' || str[j] == '\n')
			j++;
		else
		{
			count++;
			break ;
		}
	}
	return (count);
}

int	count_map_len(char *argv)
{
	char	*str;
	int		fd;
	int		count;
	int		j;

	j = 0;
	count = 0;
	fd = open(argv, O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		j = 0;
		if (count < 6)
			count = count_map_len2(str, j, count);
		else
			count++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (count);
}
