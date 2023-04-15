#include "cub3d.h"

void	matrix_free(char **str)
{
	int	j;

	j = 0;
	while (str && str[j])
	{
		free(str[j]);
		j++;
	}
	free(str);
}
