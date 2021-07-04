#include "so_long.h"

extern int	checkmap(t_map *map);
extern void	error(void);

static void	getlength(char **argv, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &line);
	map->lenght = (int)ft_strlen(line);
	free(line);
	while (get_next_line(fd, &line))
	{
		if (map->lenght != (int)ft_strlen(line))
			error();
		free(line);
	}
	free(line);
	close(fd);
}

static void	getheight(char **argv, t_map *map)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	map->height = 0;
	while (get_next_line(fd, &line))
	{
		map->height++;
		free(line);
	}
	free(line);
	close(fd);
}

static void	getmap(char **argv, t_map *map)
{
	int		fd;
	int		i;
	char	*line;

	map->map = (char **)malloc(sizeof(char *) * (map->height + 1));
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line))
	{
		map->map[i] = line;
		i++;
	}
	free(line);
	map->map[i] = NULL;
	close(fd);
}

void	parser(char **argv, t_map *map)
{
	getlength(argv, map);
	getheight(argv, map);
	getmap(argv, map);
	checkmap(map);
}
