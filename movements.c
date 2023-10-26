/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:22:27 by phanosek          #+#    #+#             */
/*   Updated: 2023/10/25 20:11:17 by phanosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/so_long.h"

static void	move_resume(t_data *data, int x, int y, int dir)
{
	if (dir == UP)
		y -= 1;
	if (dir == DOWN)
		y += 1;
	if (dir == LEFT)
		x -= 1;
	if (dir == RIGHT)
		x += 1;
	if (data->map.map[y][x] == 'E' && data->map.c == 0)
		return (ft_win(data));
	if (data->map.map[y][x] == 'C')
	{
		data->map.map[y][x] = '0';
		data->map.c--;
	}
}

void	move_up(t_data *data)
{
	int	x;
	int	y;

	x = data->play.x;
	y = data->play.y;
	if (y > 0 && data->map.map[y - 1][x] != '1')
	{
		move_resume(data, x, y, UP);
		if (data->map.map[y - 1][x] == 'E' && (data->map.c != 0 ||
			data->map.e == 1))
			return ;
		data->steps_count++;
		mlx_put_image_to_window(data->mlx, data->win, data->img.ground,
			x * IMG_PXL, y * IMG_PXL);
		data->map.map[y][x] = '0';
		y--;
		steps_counter(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.ground,
			x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(data->mlx, data->win, data->img.player,
			x * IMG_PXL, y * IMG_PXL);
		data->map.map[y][x] = 'P';
		data->play.x = x;
	}
}

void	move_left(t_data *data)
{
	int	x;
	int	y;

	x = data->play.x;
	y = data->play.y;
	if (x > 0 && data->map.map[y][x - 1] != '1')
	{
		move_resume(data, x, y, LEFT);
		if (data->map.map[y][x - 1] == 'E' && (data->map.c != 0 ||
			data->map.e == 1))
			return ;
		data->steps_count++;
		mlx_put_image_to_window(data->mlx, data->win, data->img.ground,
			x * IMG_PXL, y * IMG_PXL);
		data->map.map[y][x] = '0';
		x--;
		steps_counter(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.ground,
			x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(data->mlx, data->win, data->img.player,
			x * IMG_PXL, y * IMG_PXL);
		data->map.map[y][x] = 'P';
		data->play.y = y;
	}
}

void	move_down(t_data *data)
{
	int	x;
	int	y;

	x = data->play.x;
	y = data->play.y;
	if (y < data->y && data->map.map[y + 1][x] != '1')
	{
		move_resume(data, x, y, DOWN);
		if (data->map.map[y + 1][x] == 'E' && (data->map.c != 0 ||
			data->map.e == 1))
			return ;
		data->steps_count++;
		mlx_put_image_to_window(data->mlx, data->win, data->img.ground,
			x * IMG_PXL, y * IMG_PXL);
		data->map.map[y][x] = '0';
		y++;
		mlx_put_image_to_window(data->mlx, data->win, data->img.ground,
			x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(data->mlx, data->win, data->img.player,
			x * IMG_PXL, y * IMG_PXL);
		data->map.map[y][x] = 'P';
		steps_counter(data);
		data->play.y = y;
	}
}

void	move_right(t_data *data)
{
	int	x;
	int	y;

	x = data->play.x;
	y = data->play.y;
	if (x < data->x && data->map.map[y][x + 1] != '1')
	{
		move_resume(data, x, y, RIGHT);
		if (data->map.map[y][x + 1] == 'E' && (data->map.c != 0 ||
			data->map.e == 1))
			return ;
		data->steps_count++;
		mlx_put_image_to_window(data->mlx, data->win, data->img.ground,
			x * IMG_PXL, y * IMG_PXL);
		data->map.map[y][x] = '0';
		x++;
		mlx_put_image_to_window(data->mlx, data->win, data->img.ground,
			x * IMG_PXL, y * IMG_PXL);
		mlx_put_image_to_window(data->mlx, data->win, data->img.player,
			x * IMG_PXL, y * IMG_PXL);
		data->map.map[y][x] = 'P';
		steps_counter(data);
	}
	data->play.x = x;
}
