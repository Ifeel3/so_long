#include "so_long.h"

static void	init(t_game *game)
{
	game->data.mlx = mlx_init();
	game->data.win = mlx_new_window(game->data.mlx, game->map.lenght * 32,
			game->map.height * 32, "so_long");
	drawmap(&game->imgs, &game->data, &game->map);
	game->moves = 0;
	playerpos(game);
	countcoins(game);
	game->num = ft_strdup("");
	mlx_string_put(game->data.mlx, game->data.win, 0, 0, 0x00000000, "0");
}

int	closegame(void)
{
	exit(0);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 0)
		moveleft(game);
	if (keycode == 1)
		movedown(game);
	if (keycode == 2)
		moveright(game);
	if (keycode == 13)
		moveup(game);
	mlx_put_image_to_window(game->data.mlx,
		game->data.win, game->imgs.wall.img, 0, 0);
	game->tmp = game->num;
	game->num = ft_itoa(game->moves);
	free((*game).tmp);
	mlx_string_put(game->data.mlx, game->data.win, 0, 0, 0x00000000, game->num);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	checkfile(argc, argv);
	parser(argv, &game.map);
	init(&game);
	mlx_key_hook(game.data.win, key_hook, &game);
	mlx_hook(game.data.win, 17, 1L << 2, closegame, 0);
	mlx_loop(game.data.mlx);
}
