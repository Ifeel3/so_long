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

void	checkfile(int argc, char **argv);
void	parser(char **argv, t_map *map);
#endif