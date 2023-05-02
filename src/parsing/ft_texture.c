/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:07:36 by manykhac          #+#    #+#             */
/*   Updated: 2023/05/02 12:07:39 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	texture_extension(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	i = len - 1;
	while (str[i])
	{
		if (str[i] == 'm' && str[i - 1]
			&& str[i - 1] == 'p' && str[i - 2]
			&& str[i - 2] == 'x' && str[i - 3]
			&& str[i - 3] == '.')
			return (0);
		else
		{
			free(str);
			return (1);
		}
	}
	return (0);
}

int	texture_check2(char *str, t_info **info, int flag)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		free(str);
		return (1);
	}
	if (texture_extension(str))
		return (1);
	if (texture_to_info(str, info, flag))
		return (1);
	return (0);
}

int	texture_check(char **g_map, int i, t_info **info, int flag)
{
	char	*str;
	int		start;
	int		end;
	int		j;

	j = 0;
	while (g_map[i][j] == ' ' || g_map[i][j] == '\t' )
			j++;
	j += 2;
	while (g_map[i][j] == ' ' || g_map[i][j] == '\t')
			j++;
	start = j;
	while (g_map[i][j] != ' ' && g_map[i][j] != '\n' && g_map[i][j] != '\t')
			j++;
	end = j;
	while (g_map[i][j] == ' ' || g_map[i][j] == '\t')
			j++;
	if (g_map[i][j] != ' ' && g_map[i][j] != '\n' && g_map[i][j] != '\t')
		return (1);
	str = ft_substr(g_map[i], start, end - start);
	if (texture_check2(str, info, flag))
		return (1);
	return (0);
}

int	texture_check_to_info(char **gen_map, int i, int j, t_info **info)
{
	(void)info;
	if (gen_map[i][j] == 'N' && gen_map[i][j + 1] == 'O')
	{
		if (texture_check(gen_map, i, info, 1))
			return (1);
	}
	if (gen_map[i][j] == 'S' && gen_map[i][j + 1] == 'O')
	{
		if (texture_check(gen_map, i, info, 2))
			return (1);
	}
	if (gen_map[i][j] == 'W' && gen_map[i][j + 1] == 'E')
	{
		if (texture_check(gen_map, i, info, 3))
			return (1);
	}
	if (gen_map[i][j] == 'E' && gen_map[i][j + 1] == 'A')
	{
		if (texture_check(gen_map, i, info, 4))
			return (1);
	}
	return (0);
}

int	ft_texture(char **gen_map, int i, t_info **info)
{
	int	j;

	(void)info;
	j = 0;
	while (gen_map[i][j] == ' ' || gen_map[i][j] == '\t')
			j++;
	if ((gen_map[i][j] == 'N' && gen_map[i][j + 1] == 'O')
		|| (gen_map[i][j] == 'S' && gen_map[i][j + 1] == 'O')
		|| (gen_map[i][j] == 'W' && gen_map[i][j + 1] == 'E')
		|| (gen_map[i][j] == 'E' && gen_map[i][j + 1] == 'A'))
	{
		if (!gen_map[i][j + 2] || (gen_map[i][j + 2]
		&& gen_map[i][j + 2] != ' ' && gen_map[i][j + 2] != '\t'))
		{
			printf("Error in texture\n");
			return (1);
		}
		else if (texture_check_to_info(gen_map, i, j, info))
		{
			printf("Error in TEXTURE\n");
			return (1);
		}
	}
	return (0);
}
