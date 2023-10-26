/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_and_steps.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:48:12 by phanosek          #+#    #+#             */
/*   Updated: 2023/10/25 19:35:36 by phanosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/so_long.h"

void	parse_characters(t_data *data, int width, int i, int j)
{
	if (data->map.map[i][j] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.wall, width, i * IMG_PXL);
	else if (data->map.map[i][j] == 'P')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.player, width, i * IMG_PXL);
	else if (data->map.map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.collectible, width, i * IMG_PXL);
	else if (data->map.map[i][j] == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.exit, width, i * IMG_PXL);
	else if (data->map.map[i][j] == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->img.ground, width, i * IMG_PXL);
}

int	render(t_data *data)
{
	int		i;
	size_t	j;
	int		width;

	if (data->win == NULL)
		return (FAILURE);
	i = 0;
	j = 0;
	width = 0;
	while (data->map.map[i])
	{
		while (data->map.map[i][j] && data->map.map[i][j] != '\n')
		{
			parse_characters(data, width, i, j);
			width += IMG_PXL;
			j++;
		}
		j = 0;
		width = 0;
		i++;
	}
	return (SUCCESS);
}
