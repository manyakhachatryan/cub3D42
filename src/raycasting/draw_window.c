/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:10:58 by manykhac          #+#    #+#             */
/*   Updated: 2023/05/02 12:11:01 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int r, int g, int b)
{
	int	t;

	t = 0;
	return (*(int *)(unsigned char [4]){b, g, r, t});
}

void	initializer(t_addres *address)
{
	address->game->mlx = mlx_init();
	address->game->win = mlx_new_window(address->game->mlx, WIDTH, \
	HEIGHT, "Welcome Manya's and Lian's cube!");
	address->game->no = mlx_xpm_file_to_image(address->game->mlx, \
	address->elements._no, &address->img[1].width, &address->img[1].height);
	address->game->so = mlx_xpm_file_to_image(address->game->mlx, \
	address->elements._so, &address->img[2].width, &address->img[2].height);
	address->game->ea = mlx_xpm_file_to_image(address->game->mlx, \
	address->elements._ea, &address->img[3].width, &address->img[3].height);
	address->game->we = mlx_xpm_file_to_image(address->game->mlx, \
	address->elements._we, &address->img[4].width, &address->img[4].height);
	address->game->f_color = create_trgb(address->elements._f[0], \
	address->elements._f[1], address->elements._f[2]);
	address->game->c_color = create_trgb(address->elements._c[0], \
	address->elements._c[1], address->elements._c[2]);
	if (address->game->mlx == NULL || address->game->win == NULL)
		close_game(address);
	if (address->game->no == NULL || address->game->so == NULL)
		close_game(address);
	if (address->game->we == NULL || address->game->ea == NULL)
		close_game(address);
}
