/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:14:21 by phanosek          #+#    #+#             */
/*   Updated: 2023/10/26 13:00:13 by phanosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/so_long.h"

void	error_message_filename(void)
{
	write(2, "\033[1;31m🛑ERROR: ", 17);
	write(2, "Wrong extension - should be .ber\n\033[0m", 35);
	exit(EXIT_FAILURE);
}

void	error_message_edges(t_data *data)
{
	write(2, "\033[1;31m🛑ERROR: ", 17);
	write(2, "Walls are not on all sides of the map.\n\033[0m", 45);
	ft_free_array(data->map.map, data->y);
	ft_free_array(data->map_2, data->y);
	exit(EXIT_FAILURE);
}

void	error_message_open(void)
{
	write(2, "\033[1;31m🛑ERROR: ", 17);
	write(2, "Cannot open the file.\n\033[0m", 25);
	exit(EXIT_FAILURE);
}

void	error_message_size(t_data *data)
{
	write(2, "\033[1;31m🛑ERROR: ", 17);
	write(2, "Wrong size of the map; not rectangle.\n\033[0m", 37);
	ft_free_array(data->map.map, data->y);
	ft_free_array(data->map_2, data->y);
	exit(EXIT_FAILURE);
}

void	error_message_elements(t_data *data)
{
	write(2, "\033[1;31m🛑ERROR: ", 17);
	write(2, "Elements missing OR more elements/chars present.\n\033[0m", 54);
	ft_free_array(data->map.map, data->y);
	ft_free_array(data->map_2, data->y);
	exit(EXIT_FAILURE);
}
