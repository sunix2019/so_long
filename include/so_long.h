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
# include "get_next_line.h"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_DESTROY_NOTIFY 17
# define NO_EVENT_MASK 0L

# define KEY_ESC 0xff1b

# define TILE_SIZE 64

typedef struct s_map
{
	int			**map;
	int			row;
	int			col;
}				t_map;

typedef struct	s_player
{
	int			x;
	int			y;
}				t_player;

typedef struct	s_img
{
	void		*img;
	int			width;
	int			height;
}				t_img;

typedef struct	s_game
{
	void		*mlx;
	void		*win;
	t_map		map;
	t_player	player;
	t_img		imgs[3];
}				t_game;

void	game_init(t_game *game);
void	window_init(t_game *game);
void	img_init(t_game *game);
int		click_cross_mark(int key, t_game *game);
int		deal_key(int key, t_game *game);
int		render_next_frame(t_game *game);
void	my_error(char *msg);
int		map_create(t_map *map, t_list *list);
void	map_put(t_map *map);
void	map_check(t_map *map);
void	read_file(t_list **list, char *file_path);

#endif
