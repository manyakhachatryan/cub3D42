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
			if (flag > 1)
			{
				printf("Dublicte symbols in map\n");
				return (1);
			}
		j++;
		}
		i++;
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

int	check_empty_line(char **gen_map, int i, int index)
{
	int	j;

	j = 0;
	while (i <= index)
	{
		j = 0;
		while (gen_map[i][j])
		{
			if ((gen_map[i][j] == ' ' && gen_map[i][j + 1] == '\n')
			|| gen_map[i][j] == '\n')
			{
				printf("ERRRR\n");
				return (1);
			}
			else if (gen_map[i][j] == ' ')
				j++;
			else if (gen_map[i][j] != ' ' && gen_map[i][j] != '\n')
				break ;
		j++;
		}
	i++;
	}
	return (0);
}

int	find_index(char **gen_map)
{
	int	i;
	int	j;

	j = 0;
	i = matrix_len(gen_map);
	i--;
	while (gen_map[i] && i >= 0)
	{
		j = 0;
		while (gen_map[i][j])
		{
			if (gen_map[i][j] == ' ' || gen_map[i][j] == '\t')
				j++;
			else if (gen_map[i][j] != ' ' && gen_map[i][j] != '\t'
				&& gen_map[i][j] != '\n')
			{
				return (i);
			}
			else if (gen_map[i][j] == '\n' && !gen_map[i][j + 1])
				break ;
		}
	i--;
	}
	return (i);
}

int	divide_map(char **gen_map, t_info **info)
{
	int	i;
	int	j;
	int	index;

	(void)info;
	index = 0;
	i = 6;
	j = 0;
	index = find_index(gen_map);
	if (check_empty_line(gen_map, i, index)
		|| check_valid_map(gen_map, i, index)
		|| dublicte_symbol(gen_map, i, index))
		return (1);
	separate_map(info, gen_map, index, i);
	return (0);
}

int	divide_clr_txtr(char **gen_map, t_info **info)
{
	int	count;
	int	i;

	(void)info;
	count = 0;
	i = 0;
	while (i < 6)
	{
		if (ft_colors(gen_map, i, info, &count))
			return (1);
		if (ft_texture(gen_map, i, info))
			return (1);
		i++;
	}
	if ((*info)->flag_c_f && (*info)->flag_c_c && (*info)->flag_tex_no
		&& (*info)->flag_tex_so && (*info)->flag_tex_we && (*info)->flag_tex_ea)
		return (0);
	else
	{
		printf("Txt and color error\n");
		return (1);
	}
}

int	divide_gen_map(char **gen_map, t_info **info)
{
	(void)info;
	if (divide_clr_txtr(gen_map, info))
		return (1);
	if (divide_map(gen_map, info))
		return (1);
	if (check_zero((*info)->game_map))
		return (1);
	return (0);
}
