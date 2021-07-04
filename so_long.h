#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
}	t_data;

typedef struct s_map
{
	char	**map;
	int		height;
	int		lenght;
}	t_map;

typedef struct s_img
{
	void	*img;
	int		img_width;
	int		img_height;
}	t_img;

typedef struct s_imgs
{
	t_img	coin;
	t_img	player;
	t_img	exit;
	t_img	space;
	t_img	wall;
}	t_imgs;

typedef struct s_game
{
	t_data	data;
	t_map	map;
	t_imgs	imgs;
	char	*num;
	char	*tmp;
	int		moves;
	int		posx;
	int		posy;
	int		coins;
}	t_game;

void	checkfile(int argc, char **argv);
void	parser(char **argv, t_map *map);
void	drawmap(t_imgs *imgs, t_data *data, t_map *map);
void	moveup(t_game *game);
void	movedown(t_game *game);
void	moveleft(t_game *game);
void	moveright(t_game *game);
void	playerpos(t_game *game);
void	countcoins(t_game *game);
#endif