/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_colors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:07:20 by manykhac          #+#    #+#             */
/*   Updated: 2023/05/02 12:07:24 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_color_argument(char **color_map)
{
	int	i;

	i = 0;
	while (color_map[i])
	{
		if (ft_atoi(color_map[i]) >= 0 && ft_atoi(color_map[i]) <= 255)
			i++;
		else
			return (1);
	}
	return (0);
}

int	split_color_argument(char *str, t_info **info, char c)
{
	char	**color_map;
	int		len;

	(void)c;
	(void)info;
	len = 0;
	color_map = ft_split(str, ',');
	free(str);
	len = matrix_len(color_map);
	if (len != 3 || check_color_argument(color_map))
	{
		matrix_free(color_map);
		return (1);
	}
	if (color_to_info(color_map, info, c))
		return (1);
	return (0);
}

int	parse_clr_argument(char *str, t_info **info, char c)
{
	int		i;

	(void)info;
	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ',' || str[i] == '\n')
			i++;
		else
		{
			free(str);
			return (1);
		}
	}
	if (split_color_argument(str, info, c))
		return (1);
	return (0);
}

int	parse_color(char **gen_map, int i, int j, t_info **info)
{
	int		start;
	int		end;
	char	c;

	start = 0;
	end = 0;
	(void)info;
	c = gen_map[i][j];
	j++;
	while (gen_map[i][j] && (gen_map[i][j] == ' ' || gen_map[i][j] == '\t'))
		j++;
	start = j;
	while (gen_map[i][j] && gen_map[i][j] != ' ' && gen_map[i][j] != '\t')
		j++;
	end = j;
	if (gen_map[i][j])
	{
		while (gen_map[i][j] && (gen_map[i][j] == ' ' || gen_map[i][j] == '\t'))
			j++;
		if (gen_map[i][j] && gen_map[i][j] != '\n')
			return (1);
	}
	if (parse_clr_argument(ft_substr(gen_map[i], start, end - start), info, c))
		return (1);
	return (0);
}

int	ft_colors(char **gen_map, int i, t_info **info, int *count)
{
	int	j;

	(void)info;
	j = 0;
	while (gen_map[i][j] == ' ' || gen_map[i][j] == '\t')
			j++;
	if (gen_map[i][j] == 'F' || gen_map[i][j] == 'C')
	{
		if (!gen_map[i][j + 1] || (gen_map[i][j + 1]
		&& gen_map[i][j + 1] != ' ' && gen_map[i][j + 1] != '\t'))
		{
			printf("Colors identifier must be 'F' or 'C'\n");
			return (1);
		}
		if (parse_color(gen_map, i, j, info))
		{
			printf("Invalid argument for color\n");
			return (1);
		}
	(*count)++;
	}
	return (0);
}
