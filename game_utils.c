/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:30:05 by phanosek          #+#    #+#             */
/*   Updated: 2023/10/25 19:52:26 by phanosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/so_long.h"

void	initialize_win(t_data *data)
{
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		free(data->mlx);
	data->win = mlx_new_window(data->mlx, data->x * IMG_PXL,
			data->y * IMG_PXL, TREASURE);
	if (data->win == NULL)
		free(data->win);
}

void	initialize_img(t_data *data)
{
	data->img.ground = mlx_xpm_file_to_image(data->mlx,
			GROUND, &data->img.width, &data->img.height);
	data->img.exit = mlx_xpm_file_to_image(data->mlx,
			EXIT_LOCKED, &data->img.width, &data->img.height);
	data->img.player = mlx_xpm_file_to_image(data->mlx,
			PLAYER, &data->img.width, &data->img.height);
	data->img.wall = mlx_xpm_file_to_image(data->mlx,
			WALL, &data->img.width, &data->img.height);
	data->img.collectible = mlx_xpm_file_to_image(data->mlx,
			COLLECTIBLE, &data->img.width, &data->img.height);
}
