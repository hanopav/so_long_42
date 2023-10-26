/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:51:18 by phanosek          #+#    #+#             */
/*   Updated: 2023/10/25 19:46:11 by phanosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/so_long.h"

void	move_on_paths(int x, int y, t_data *data)
{
	char	type;

	type = data->map_2[y][x];
	if (type == 'C')
	{
		data->map.count_c -= 1;
		data->map_2[y][x] = '1';
	}
	else if (type == 'E')
	{
		data->map.count_e -= 1;
		data->map_2[y][x] = '1';
	}
	else if (type == '0' || type == 'P')
		data->map_2[y][x] = '1';
	else
		return ;
	move_on_paths(x + 1, y, data);
	move_on_paths(x - 1, y, data);
	move_on_paths(x, y + 1, data);
	move_on_paths(x, y - 1, data);
}

void	check_valid_path(t_data *data)
{
	data->map.count_c = data->map.c;
	data->map.count_e = data->map.e;
	scan_player(data);
	move_on_paths(data->play.x, data->play.y, data);
	if (data->map.count_c != 0 || data->map.count_e >= data->map.e)
	{
		write(2, "\033[1;31m🛑ERROR: ", 19);
		write(2, "NO VALID PATH\n\033[0m", 19);
		ft_free_array(data->map.map, data->y);
		ft_free_array(data->map_2, data->y);
		exit(EXIT_FAILURE);
	}
}
