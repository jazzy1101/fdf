/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coloring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 08:42:59 by dabae             #+#    #+#             */
/*   Updated: 2024/04/02 11:00:32 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	get_max_z(t_param *param)
{
	int	tmp;
	int	x;
	int	y;

	tmp = param->map[0][0].z;
	y = 0;
	while (y < param->map_len)
	{
		x = 0;
		while (x < param->map_wid)
		{
			if (param->map[y][x].z > tmp)
				tmp = param->map[y][x].z;
			x++;
		}
		y++;
	}
	param->max_z = tmp;
}

void	get_min_z(t_param *param)
{
	int	tmp;
	int	x;
	int	y;

	tmp = param->map[0][0].z;
	y = 0;
	while (y < param->map_len)
	{
		x = 0;
		while (x < param->map_wid)
		{
			if (param->map[y][x].z < tmp)
				tmp = param->map[y][x].z;
			x++;
		}
		y++;
	}
	param->min_z = tmp;
}

void	set_color(t_param *param)
{
	int	x;
	int	y;
	int	range;

	range = param->max_z - param->min_z;
	y = 0;
	while (y < param->map_len)
	{
		x = 0;
		while (x < param->map_wid)
		{
			if (param->map[y][x].z == 0)
				param->map[y][x].color = create_trgb(0, 0, 0, 150);
			else if (param->map[y][x].z < 0)
				param->map[y][x].color = create_trgb(0, 200
						+ (param->map[y][x].z / range), 0, 100);
			else if (param->map[y][x].z > 0)
				param->map[y][x].color = create_trgb(0, 0, 200
						* (param->map[y][x].z / range), 100);
			x++;
		}
		y++;
	}
}
