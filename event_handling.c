/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:49:48 by phanosek          #+#    #+#             */
/*   Updated: 2023/10/26 13:05:59 by phanosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/so_long.h"

void	scan_player(t_data *data)
{
	data->play.y = 0;
	data->play.x = 0;
	while (data->play.y < data->y)
	{
		while (data->play.x < data->x)
		{
			if (data->map.map[data->play.y][data->play.x] == 'P')
				break ;
			data->play.x++;
		}
		if (data->map.map[data->play.y][data->play.x] == 'P')
			break ;
		data->play.x = 0;
		data->play.y++;
	}
}

int	key_hook(int keycode, t_data *data)
{
	scan_player(data);
	if (keycode == ESC)
		return (ft_close(data));
	else if (data->map.count_e == 1)
		return (0);
	else if (keycode == LEFT)
		move_left(data);
	else if (keycode == DOWN)
		move_down(data);
	else if (keycode == RIGHT)
		move_right(data);
	else if (keycode == UP)
		move_up(data);
	return (0);
}

void	ft_win(t_data *data)
{
	data->map.e = 1;
	data->steps_count++;
	mlx_clear_window(data->mlx, data->win);
	mlx_string_put(data->mlx, data->win,
		data->x / 2 * IMG_PXL, data->y / 2 * IMG_PXL, 0xFFFA9E, "YOU WON");
	write(1, "\n", 1);
	write(1, "\x1b[32;01m", 9);
	write(1, "🏆🏆YOU WON!!🏆🏆\n", 27);
	write(1, "\x1b[0m", 5);
}

int	ft_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	ft_free_array(data->map.map, data->y);
	exit(EXIT_SUCCESS);
	return (0);
}
