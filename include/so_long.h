/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsekiguc <tsekiguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 23:18:51 by tsekiguc          #+#    #+#             */
/*   Updated: 2021/12/09 15:20:43 by tsekiguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

# include "mlx.h"
# include "libft.h"

# define DESTROY_NOTIFY 17
# define KEY_PRESS 2
# define MAP_NOTIFY 19
# define NO_EVENT_MASK 0L

# define KEY_ESC 0xff1b
# define KEY_W 0x77
# define KEY_S 0x73
# define KEY_A 0x61
# define KEY_D 0x64

# define TILE_SIZE 32

# define GRASS			"./texture/grass.xpm"
# define FLOWER			"./texture/flower.xpm"
# define TREASURE		"./texture/treasure.xpm"
# define GOAL			"./texture/goal.xpm"
# define NORTH			"./texture/north.xpm"
# define SOUTH			"./texture/south.xpm"
# define EAST			"./texture/east.xpm"
# define WEST			"./texture/west.xpm"

typedef enum e_mapinfo
{
	EMPTY = 0,
	WALL,
	COLLECTIBLE,
	EXIT,
	UP,
	DOWN,
	RIGHT,
	LEFT,
}			t_mapinfo;

typedef struct s_map
{
	int			**map;
	int			row;
	int			col;
}				t_map;

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct s_img
{
	void		*img;
	int			width;
	int			height;
}				t_img;

typedef struct s_window
{
	int			row;
	int			col;
}				t_window;

typedef struct s_area
{
	int			x;
	int			y;
}				t_area;

typedef struct s_matrix
{
	int			row;
	int			col;
}				t_matrix;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_map			map;
	t_player		player;
	t_img			img;
	t_img			texs[8];
	t_window		window;
	int				c_cnt;
}				t_game;

int		extension_check(char *file_path);
void	game_init(t_game *game);
void	window_init(t_game *game);
void	img_init(t_img texs[], void *mlx);
int		game_exit(t_game *game);
int		deal_key(int key, t_game *game);
int		render_next_frame(t_game *game, int x, int y);
void	my_error(char *msg);
void	my_perror(void);
void	map_create(t_map *map, t_list *list);
void	map_put(t_map *map);
void	map_check(t_game *game, int c_cnt, int e_cnt, int p_cnt);
void	read_file(t_list **list, char *file_path);
void	command_count_put(void);
void	clear_check(t_game *game, int clear, int *finish_position);
void	get_player_position(t_game *game);

#endif
