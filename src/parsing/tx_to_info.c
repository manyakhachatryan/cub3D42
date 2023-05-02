/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tx_to_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manykhac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 12:08:55 by manykhac          #+#    #+#             */
/*   Updated: 2023/05/02 12:09:00 by manykhac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	texture_to_info2(char *str, t_info **info, int flag)
{
	if (flag == 3)
	{
		if ((*info)->flag_tex_we)
			return (1);
	(*info)->flag_tex_we = 1;
	(*info)->texture_we = str;
	}
	if (flag == 4)
	{
		if ((*info)->flag_tex_ea)
			return (1);
	(*info)->flag_tex_ea = 1;
	(*info)->texture_ea = str;
	}
	return (0);
}

int	texture_to_info(char *str, t_info **info, int flag)
{
	if (flag == 1)
	{
		if ((*info)->flag_tex_no)
			return (1);
	(*info)->flag_tex_no = 1;
	(*info)->texture_no = str;
	}
	else if (flag == 2)
	{
		if ((*info)->flag_tex_so)
			return (1);
	(*info)->flag_tex_so = 1;
	(*info)->texture_so = str;
	}
	else if (texture_to_info2(str, info, flag))
		return (1);
	return (0);
}
