#include "so_long.h"

void	moveup(t_game *game)
{
	if (game->map.map[game->posy - 1][game->posx] != '1')
	{
		if (game->map.map[game->posy - 1][game->posx] == 'C')
		{
			game->map.map[game->posy - 1][game->posx] = '0';
			countcoins(game);
		}
		if (game->map.map[game->posy - 1][game->posx] == 'E'
			&& game->coins == 0)
			exit(0);
		else if (game->map.map[game->posy - 1][game->posx] != 'E')
		{
			mlx_put_image_to_window(game->data.mlx, game->data.win,
				game->imgs.space.img, game->posx * 32, game->posy * 32);
			mlx_put_image_to_window(game->data.mlx, game->data.win,
				game->imgs.space.img, game->posx * 32, (game->posy - 1) * 32);
			mlx_put_image_to_window(game->data.mlx, game->data.win,
				game->imgs.player.img, game->posx * 32, (game->posy - 1) * 32);
			game->map.map[game->posy - 1][game->posx] = 'P';
			game->map.map[game->posy][game->posx] = '0';
			game->posy--;
			game->moves++;
		}
	}
}

void	movedown(t_game *game)
{
	if (game->map.map[game->posy + 1][game->posx] != '1')
	{
		if (game->map.map[game->posy + 1][game->posx] == 'C')
		{
			game->map.map[game->posy + 1][game->posx] = '0';
			countcoins(game);
		}
		if (game->map.map[game->posy + 1][game->posx] == 'E'
			&& game->coins == 0)
			exit(0);
		else if (game->map.map[game->posy + 1][game->posx] != 'E')
		{
			mlx_put_image_to_window(game->data.mlx, game->data.win,
				game->imgs.space.img, game->posx * 32, game->posy * 32);
			mlx_put_image_to_window(game->data.mlx, game->data.win,
				game->imgs.space.img, game->posx * 32, (game->posy + 1) * 32);
			mlx_put_image_to_window(game->data.mlx, game->data.win,
				game->imgs.player.img, game->posx * 32, (game->posy + 1) * 32);
			game->map.map[game->posy + 1][game->posx] = 'P';
			game->map.map[game->posy][game->posx] = '0';
			game->posy++;
			game->moves++;
		}
	}
}

void	moveleft(t_game *game)
{
	if (game->map.map[game->posy][game->posx - 1] != '1')
	{
		if (game->map.map[game->posy][game->posx - 1] == 'C')
		{
			game->map.map[game->posy][game->posx - 1] = '0';
			countcoins(game);
		}
		if (game->map.map[game->posy][game->posx - 1] == 'E'
			&& game->coins == 0)
			exit(0);
		else if (game->map.map[game->posy][game->posx - 1] != 'E')
		{
			mlx_put_image_to_window(game->data.mlx, game->data.win,
				game->imgs.space.img, game->posx * 32, game->posy * 32);
			mlx_put_image_to_window(game->data.mlx, game->data.win,
				game->imgs.space.img, (game->posx - 1) * 32, game->posy * 32);
			mlx_put_image_to_window(game->data.mlx, game->data.win,
				game->imgs.player.img, (game->posx - 1) * 32, game->posy * 32);
			game->map.map[game->posy][game->posx - 1] = 'P';
			game->map.map[game->posy][game->posx] = '0';
			game->posx--;
			game->moves++;
		}
	}
}

void	moveright(t_game *game)
{
	if (game->map.map[game->posy][game->posx + 1] != '1')
	{
		if (game->map.map[game->posy][game->posx + 1] == 'C')
		{
			game->map.map[game->posy][game->posx + 1] = '0';
			countcoins(game);
		}
		if (game->map.map[game->posy][game->posx + 1] == 'E'
			&& game->coins == 0)
			exit(0);
		else if (game->map.map[game->posy][game->posx + 1] != 'E')
		{
			mlx_put_image_to_window(game->data.mlx, game->data.win,
				game->imgs.space.img, game->posx * 32, game->posy * 32);
			mlx_put_image_to_window(game->data.mlx, game->data.win,
				game->imgs.space.img, (game->posx + 1) * 32, game->posy * 32);
			mlx_put_image_to_window(game->data.mlx, game->data.win,
				game->imgs.player.img, (game->posx + 1) * 32, game->posy * 32);
			game->map.map[game->posy][game->posx + 1] = 'P';
			game->map.map[game->posy][game->posx] = '0';
			game->posx++;
			game->moves++;
		}
	}
}
