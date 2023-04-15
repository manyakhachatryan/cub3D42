#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_info	*info;

	info = malloc(sizeof(t_info));
	info->colors_c =malloc(sizeof(char *) * 4);
	info->colors_f =malloc(sizeof(char *) * 4);
	info->flag_c_f = 0;
	info->flag_c_c = 0;
	info->flag_tex_no = 0;
	info->flag_tex_so = 0;
	info->flag_tex_we = 0;
	info->flag_tex_ea = 0;
	if (parsing(argc, argv, &info))
	{
		//sleep(1000);
		return (1);
	}
	int i = 0;
		// printf("clor = %d\n", info->flag_c_f);
	while (info->flag_c_c && info->colors_c[i])
	{
		printf("clor = %s\n", info->colors_c[i]);
		i++;
	}
	i = 0;
	while (info->flag_c_f && info->colors_f[i])
	{
		printf("colors = %s\n", info->colors_f[i]);
		i++;
	}
	printf("texture_no=%s\n", info->texture_no);
	printf("texture_so=%s\n", info->texture_so);
	printf("texture_we=%s\n", info->texture_we);
	printf("texture_ea=%s\n", info->texture_ea);
 int j = 0;
	while((info)->game_map[j])
	{
		printf("++++++%s\n", (info)->game_map[j]);
		// (*info)->game_map[0][j] = gen_map[i][j];
		j++;
	}
	//sleep(1000);
	return (0);
}
