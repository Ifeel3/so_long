#include "so_long.h"

void	playerpos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.lenght)
		{
			if (game->map.map[i][j] == 'P')
			{
				game->posx = i;
				game->posy = j;
				return ;
			}
			j++;
		}
		i++;
	}
}
