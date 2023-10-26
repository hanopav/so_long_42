/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 18:12:42 by phanosek          #+#    #+#             */
/*   Updated: 2023/10/26 13:38:42 by phanosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/so_long.h"
#include "../../INCLUDES/get_next_line.h"

void	check_extension(t_data *data)
{
	size_t	len;

	len = ft_strlen(data->filename);
	if (data->filename[len - 1] != 'r')
		error_message_filename();
	if (data->filename[len - 2] != 'e')
		error_message_filename();
	if (data->filename[len - 3] != 'b')
		error_message_filename();
	if (data->filename[len - 4] != '.')
		error_message_filename();
	if (!ft_strnstr(data->filename, ".ber", ft_strlen(data->filename)))
		error_message_filename();
}

static void	checker_params(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->y)
	{
		while (x < data->x)
		{
			if (data->map.map[y][x] == 'C')
				data->map.c += 1;
			else if (data->map.map[y][x] == 'E')
				data->map.e += 1;
			else if (data->map.map[y][x] == 'P')
				data->map.count_p += 1;
			else if (data->map.map[y][x] == '0' || data->map.map[y][x] == '1')
				;
			else
				error_message_elements(data);
			x++;
		}
		x = 0;
		y++;
	}
	if (data->map.c < 1 || data->map.e < 1 || data->map.count_p != 1)
		error_message_elements(data);
}

static void	checker_wall(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map.map[0][x] == '1' && data->map.map[1][x])
		x++;
	if (data->map.map[1][x] != '\0')
		error_message_edges(data);
	y = 1;
	while (y < data->y)
	{
		if (data->map.map[y][0] != '1' ||
			data->map.map[y][data->x - 1] != '1')
			error_message_edges(data);
		y++;
	}
	x = 0;
	while (data->map.map[data->y - 1][x] == '1')
		x++;
	if (data->map.map[data->y - 1][x] != '\0')
	{
		error_message_edges(data);
	}
}

void	checker_size(t_data *data)
{
	int	y;
	int	x;
	int	max;

	y = 0;
	x = 0;
	max = ft_strlen(data->map.map[y]);
	while (y < data->y)
	{
		x = ft_strlen(data->map.map[y]);
		if (max != x)
			error_message_size(data);
		y++;
	}
	data->x = max;
}

void	map_checker(t_data *data)
{
	check_extension(data);
	map_array(data);
	checker_size(data);
	checker_wall(data);
	checker_params(data);
	check_valid_path(data);
	ft_free_array(data->map_2, data->y);
}
