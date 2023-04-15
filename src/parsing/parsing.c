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

int	check_map_exist(char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		printf("Map does not exist\n");
		exit(0);
	}
	return (fd);
}

void	check_extension(char *argv)
{
	int	i;
	int	len;

	len = ft_strlen(argv);
	i = len - 1;
	while (argv[i])
	{
		if (argv[i] == 'b' && argv[i - 1]
			&& argv[i - 1] == 'u' && argv[i - 2]
			&& argv[i - 2] == 'c' && argv[i - 3]
			&& argv[i - 3] == '.')
			return ;
		else
		{
			printf("Invalid extension\n");
			exit(0);
		}
	}
}

void	check_argc(int argc)
{
	if (argc == 1)
	{
		printf("Not enough arguments\n");
		exit(0);
	}
	else if (argc > 2)
	{
		printf("Too many arguments\n");
		exit(0);
	}
}

int	parsing(int argc, char **argv, t_info **info)
{
	int		fd;
	int		i;
	char	**gen_map;

	(void)info;
	fd = 0;
	i = 0;
	gen_map = NULL;
	check_argc(argc);
	check_extension(argv[1]);
	gen_map = map_to_matrix(check_map_exist(argv[1]), count_map_len(argv[1]));
	if (divide_gen_map(gen_map, info))
	{
		matrix_free(gen_map);
		return (1);
	}
	while (gen_map[i])
	{
		printf("str[%d] = %s\n", i, gen_map[i]);
		i++;
	}
	matrix_free(gen_map);
	return (0);
}
