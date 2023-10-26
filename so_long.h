/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:51:51 by phanosek          #+#    #+#             */
/*   Updated: 2023/10/26 13:38:01 by phanosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../libft/ft_printf/ft_printf.h"

# ifndef CONTROL_DIRECTORY
#  define CONTROL_DIRECTORY 00200000
# endif

# define IMG_PXL 48
# define FAILURE 1
# define SUCCESS 0
# define COLLECTIBLE "ASSETS/coin.xpm"
# define EXIT_LOCKED "ASSETS/portal.xpm"
# define GROUND "ASSETS/ground.xpm"
# define PLAYER "ASSETS/knight.xpm"
# define WALL "ASSETS/lava.xpm"
# define EXIT "ASSETS/portal.xpm"
# define TREASURE "Treasure Hunt"
# define RESET "\033[0m"
# define COLOUR_GREEN "\033[0;32m"
# define COLOUR_RED "\033[0;31m"
# define COLOUR_BLUE "\033[0;34m"
# define COLOUR_END "\033[0m"
# define UP 	65362
# define LEFT  	65361
# define RIGHT 	65363
# define DOWN  	65364
# define ESC 	65307

//STRUCTURES USED

typedef struct s_player
{
	int	y;
	int	x;

} t_play;

typedef struct s_map
{
	int		fd;
	int		line_count;
	size_t	line_len;
	int		count_p;
	int		count_e;
	int		count_c;
	int		c;
	int		e;
	char	*path;
	char	**map;
	int		can_exit;
	int		collected;
	int		exit;

}				t_map;

typedef struct s_img
{
	void	*mlx_img;
	int		width;
	int		height;
	void	*wall;
	void	*exit;
	void	*ground;
	void	*player;
	int		line_length;
	void	*collectible;

}	t_img;

typedef struct s_data
{
	void	*mlx;
	char	*filename;
	void	*win;
	int		steps_count;
	int		p_i;
	int		p_j;
	int		i;
	int		j;
	int		win_height;
	int		win_width;
	char	**map_2;
	int		y;
	int		x;
	char	*file;
	char	*line;
	t_img	img;
	t_map	map;
	t_play	play;

}				t_data;

//INITIALIZATION

int		retrieve_line_number(char *path);
void	create_map(char *path, t_data *data);
void	put_input_in_map(int row, int column, int i, t_data *data);
void	ft_free(char **tab);
void	parse_map(t_data *data);
void	init_map(t_data *data, char **argv);
void	init_player(t_data *data);

//ERRORS

void	check_extension(t_data *data);
int		check_map(t_data *data);
void	free_map(char **map);
void 	map_checker(t_data *data);
void	check_valid_path(t_data *data);
int		ft_free_array(char **ret, int i);
void	map_array(t_data *data);
void	ft_exit_free(t_data *data);
int		ft_close(t_data *data);
int		key_hook(int keycode, t_data *data);
void	ft_win(t_data *data);
void	steps_counter(t_data *data);
void	move_up(t_data *data);
void	move_left(t_data *data);
void	move_down(t_data *data);
void	move_right(t_data *data);
void	scan_player(t_data *data);
void	map_printer(t_data *data);

void	error_message_filename(void);
void	error_message_edges(t_data *data);
void	error_message_open(void);
void	error_message_size(t_data *data);
void	error_message_elements(t_data *data);




// void		checker_size(t_data *data);
// static void	checker_wall(t_data *data);
// static void	checker_params(t_data *data);



//GRAPHICS

int		render(t_data *data);
void	parse_chars(t_data *data, int width, int i, int j);
void	initialize_win(t_data *data);
void	initialize_img(t_data *data);
void	loop_images(t_data data);
void	image_destructor(t_data data);

//EVENTS

int		keypress_handle(int keysym, t_data *data);
int		button_release_handle(t_data *data);
void	step_counter(t_data *data);
void	move_player(t_data *data, char direction);
void	collect_coins(t_data *data, char direction);
int		win_game(t_data *data);
int		check_next_tile(t_data *data, char direction, char tile);

#endif
