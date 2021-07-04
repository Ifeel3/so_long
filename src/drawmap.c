#include "so_long.h"

static void	imgsinit(t_imgs *imgs, t_data *data)
{
	imgs->wall.img = mlx_xpm_file_to_image(data->mlx,
			"img/wall.xpm",
			&imgs->wall.img_width, &imgs->wall.img_height);
	imgs->coin.img = mlx_xpm_file_to_image(data->mlx,
			"img/coin.xpm",
			&imgs->coin.img_width, &imgs->coin.img_height);
	imgs->player.img = mlx_xpm_file_to_image(data->mlx,
			"img/player.xpm",
			&imgs->player.img_width, &imgs->player.img_height);
	imgs->space.img = mlx_xpm_file_to_image(data->mlx,
			"img/space.xpm",
			&imgs->space.img_width, &imgs->space.img_height);
	imgs->exit.img = mlx_xpm_file_to_image(data->mlx,
			"img/exit.xpm",
			&imgs->exit.img_width, &imgs->exit.img_height);
}

static void	putimg(t_imgs *imgs, t_data *data, t_map *map, const int *num)
{
	if (map->map[num[0]][num[1]] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			imgs->wall.img, num[1] * 32, num[0] * 32);
	if (map->map[num[0]][num[1]] == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			imgs->space.img, num[1] * 32, num[0] * 32);
	if (map->map[num[0]][num[1]] == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			imgs->exit.img, num[1] * 32, num[0] * 32);
	if (map->map[num[0]][num[1]] == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			imgs->space.img, num[1] * 32, num[0] * 32);
		mlx_put_image_to_window(data->mlx, data->win,
			imgs->coin.img, num[1] * 32, num[0] * 32);
	}
	if (map->map[num[0]][num[1]] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			imgs->space.img, num[1] * 32, num[0] * 32);
		mlx_put_image_to_window(data->mlx, data->win,
			imgs->player.img, num[1] * 32, num[0] * 32);
	}
}

void	drawmap(t_imgs *imgs, t_data *data, t_map *map)
{
	int	num[2];

	imgsinit(imgs, data);
	num[0] = 0;
	while (num[0] < map->height)
	{
		num[1] = 0;
		while (num[1] < map->lenght)
		{
			putimg(imgs, data, map, num);
			num[1]++;
		}
		num[0]++;
	}
}
