/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:43:13 by phanosek          #+#    #+#             */
/*   Updated: 2023/10/25 19:46:41 by phanosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/so_long.h"

void	map_array(t_data *data)
{
	int		fd;

	data->y = 0;
	data->line = "";
	data->file = NULL;
	fd = open(data->filename, O_RDONLY);
	if (fd == -1)
		error_message_open();
	while (data->line)
	{
		data->line = get_next_line(fd);
		if (data->line == NULL)
			break ;
		data->file = ft_strjoinfree(data->file, data->line);
		free(data->line);
		if (!data->file)
			ft_exit_free(data);
		data->y++;
	}
	close(fd);
	data->map.map = ft_split(data->file, '\n');
	data->map_2 = ft_split(data->file, '\n');
	if (!data->map.map || !data->map_2)
		ft_exit_free(data);
	free(data->file);
}

int	ft_free_array(char **ret, int i)
{
	while (i > 0)
		free(ret[--i]);
	free(ret);
	return (0);
}

void	ft_exit_free(t_data *data)
{
	if (data->map.map)
		free(data->map.map);
	if (data->map_2)
		free(data->map_2);
	if (data->file)
		free(data->file);
	if (data->line)
		free(data->file);
	exit(EXIT_FAILURE);
}
