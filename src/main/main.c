/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lter-zak <lter-zak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:17:23 by manykhac          #+#    #+#             */
/*   Updated: 2023/05/11 15:27:33 by lter-zak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	main_init2(t_info *info, t_addres *addres)
{
	addres->cub.map = info->game_map;
	addres->elements._no = info->texture_no;
	addres->elements._so = info->texture_so;
	addres->elements._we = info->texture_we;
	addres->elements._ea = info->texture_ea;
	addres->elements._f[0] = ft_atoi(info->colors_f[0]);
	addres->elements._f[1] = ft_atoi(info->colors_f[1]);
	addres->elements._f[2] = ft_atoi(info->colors_f[2]);
	addres->elements._c[0] = ft_atoi(info->colors_c[0]);
	addres->elements._c[1] = ft_atoi(info->colors_c[1]);
	addres->elements._c[2] = ft_atoi(info->colors_c[2]);
}

void	main_init(t_info *info, t_addres *addres)
{
	addres->cub.map = NULL;
	addres->cub.texture = NULL;
	addres->elements._no = NULL;
	addres->elements._so = NULL;
	addres->elements._we = NULL;
	addres->elements._ea = NULL;
	info->colors_c = malloc(sizeof(char *) * 4);
	info->colors_f = malloc(sizeof(char *) * 4);
	info->flag_c_f = 0;
	info->flag_c_c = 0;
	info->flag_tex_no = 0;
	info->flag_tex_so = 0;
	info->flag_tex_we = 0;
	info->flag_tex_ea = 0;
}

int	main(int argc, char **argv)
{
	t_info		*info;
	t_addres	addres;

	info = malloc(sizeof(t_info));
	main_init(info, &addres);
	if (parsing(argc, argv, &info))
		return (1);
	main_init2(info, &addres);
	init_structs(&addres);
	addres.data = data_collector(addres.cub);
	initializer(&addres);
	init_win(&addres);
	mlx_hook(addres.game->win, 17, 1L << 0, close_game, &addres);
	mlx_hook(addres.game->win, 2, 1L << 0, key_manager, &addres);
	mlx_loop(addres.game->mlx);
	return (0);
}
