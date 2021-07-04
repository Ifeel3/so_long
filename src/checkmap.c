#include "so_long.h"

extern void	error(void);

static void	checkgarbage(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height - 1)
	{
		j = 0;
		while (j < map->lenght - 1)
		{
			if (!ft_strchr("10PEC", map->map[i][j]))
				error();
			j++;
		}
		i++;
	}
}

static void	checkwalls(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[0][i] == '1')
		i++;
	if (map->map[0][i])
		error();
	if (ft_strncmp(map->map[0],
			map->map[map->height - 1], ft_strlen(map->map[0])))
		error();
	i = 1;
	while (i < map->height - 1)
	{
		if (map->map[i][0] != '1' || map->map[i][map->lenght - 1] != '1')
			error();
		i++;
	}
}

static void	checkplayer(t_map *map)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	num = 0;
	while (i < map->height - 1)
	{
		j = 0;
		while (j < map->lenght - 1)
		{
			if (map->map[i][j] == 'P')
				num++;
			j++;
		}
		i++;
	}
	if (num != 1)
		error();
}

static void	check(t_map *map, char ch)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	num = 0;
	while (i < map->height - 1)
	{
		j = 0;
		while (j < map->lenght - 1)
		{
			if (map->map[i][j] == ch)
				num++;
			j++;
		}
		i++;
	}
	if (num < 1)
		error();
}

void	checkmap(t_map *map)
{
	checkgarbage(map);
	checkwalls(map);
	checkplayer(map);
	check(map, 'E');
	check(map, 'C');
}
