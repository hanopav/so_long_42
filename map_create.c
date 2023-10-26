/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:31:22 by phanosek          #+#    #+#             */
/*   Updated: 2023/10/25 19:51:33 by phanosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/so_long.h"

static void	map_type(t_data *data, int x, int y)
{
	int	type;

	type = data->map.map[y / IMG_PXL][x / IMG_PXL];
	if (type == 'C' || type == 'P' || type == 'E' || type == '0')
		mlx_put_image_to_window(data->mlx, data->win, data->img.ground, x, y);
	if (type == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.collectible, x, y);
	else if (type == 'P')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player, x + 8, y);
	else if (type == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->img.exit, x, y);
	else if (type == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->img.wall, x, y);
}

void	map_printer(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->y)
	{
		while (x < data->x)
		{
			map_type(data, x * IMG_PXL, y * IMG_PXL);
			x++;
		}
		x = 0;
		y++;
	}
}

void	steps_counter(t_data *data)
{
	char	*move;

	move = ft_itoa(data->steps_count);
	write(1, "\r", 1);
	write(1, "\x1b[33;01m", 9);
	write(1, move, ft_strlen(move));
	write(1, "\x1b[0m", 5);
	write(1, " movements", 11);
	free(move);
}
