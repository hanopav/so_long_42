/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:50:59 by phanosek          #+#    #+#             */
/*   Updated: 2023/10/26 12:47:56 by phanosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/so_long.h"

void	init_map(t_data *data, char **argv)
{
	data->filename = argv[1];
	data->y = 2;
	data->play.y = 0;
	data->play.x = 0;
	data->map.count_p = 0;
	data->map.e = 0;
	data->map.c = 0;
	data->steps_count = 0;
	data->img.height = IMG_PXL;
	data->img.width = IMG_PXL;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		init_map(&data, argv);
		map_checker(&data);
		initialize_win(&data);
		initialize_img(&data);
		render(&data);
		map_printer(&data);
		mlx_hook(data.win, 17, 0, ft_close, &data);
		mlx_key_hook(data.win, key_hook, &data);
		mlx_loop(data.mlx);
	}
	write(2, "\033[1;31m🛑ERROR:", 18);
	write(2, "Usage: ./so_long MAPS\n\033[0m", 30);
	exit(EXIT_FAILURE);
}
