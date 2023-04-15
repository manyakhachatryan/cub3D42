#include "cub3d.h"

int	map_to_matrix2(char *str, int i, char **map, int j)
{
	while (str[j])
	{
		if (str[j] == ' ' || str[j] == '\t')
			j++;
		else if (str[j] != ' ' && str[j] != '\t' && str[j] != '\n')
		{
			map[i] = str;
			i++;
			break ;
		}
		else
		{
			free(str);
			break ;
		}
	}
	return (i);
}

char	**map_to_matrix(int fd, int len)
{
	int		i;
	char	*str;
	char	**map;
	int		j;

	i = 0;
	j = 0;
	map = malloc(sizeof(char *) * (len + 1));
	str = get_next_line(fd);
	while (str)
	{
		j = 0;
		if (i <= 6)
			i = map_to_matrix2(str, i, map, j);
		else
		{
			map[i] = str;
			i++;
		}
		str = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}
