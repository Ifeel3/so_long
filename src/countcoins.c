#include "so_long.h"

void	countcoins(t_game *game)
{
	int	i;
	int	j;

	game->coins = 0;
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.lenght)
		{
			if (game->map.map[i][j] == 'C')
				game->coins++;
			j++;
		}
		i++;
	}
}
