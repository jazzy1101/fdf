/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_controls.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 07:02:41 by dabae             #+#    #+#             */
/*   Updated: 2024/03/27 14:55:22 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	close_window(t_param *param)
{
	(void)param;
	exit(0);
}

static int	key_press(int key, t_param *param, t_map **map)
{
	if (key == MAIN_PAD_ESC)
	{
	    free_map(&map, param);
		mlx_destroy_window(param->mlx, param->window);
		exit(0);
	}
	if (key == NUM_PLUS
		|| key == NUM_MINUS)
	{
		mlx_clear_window(param->mlx, param->window);
		zoom(key, param, map);
	}
	else if (key == LEFT_KEY || key == RIGHT_KEY
		|| key == UP_KEY || key == DOWN_KEY)
		move(key, param, map);
	else if (key == NUM_1 || key == NUM_4
		|| key == NUM_5 || key == NUM_6
		|| key == NUM_7 || key == NUM_8
		|| key == NUM_0 || key == MAIN_PAD_1
		|| key == MAIN_PAD_4 || key == MAIN_PAD_5
		|| key == MAIN_PAD_6 || key == MAIN_PAD_7
		|| key == MAIN_PAD_8 || key == MAIN_PAD_0)
		rotate(key, param, map);
	else if (key == NUM_3 || key == NUM_2)
		change_projection(key, param, map);
    return (0);
}

void	setting_controls(t_param *param, t_map **map)
{
	//mlx_key_hook(param->window, key_press, param);
	mlx_hook(param->window, 2, 1L << 0, key_press, map);
	mlx_hook(param->window, 17, 0, close_window, map);
}
