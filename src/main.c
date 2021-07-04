#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;
	int		i;

	checkfile(argc, argv);
	parser(argv, &map);
	ft_printf("map length=%d\n", map.lenght);
	ft_printf("map height=%d\n\n", map.height);
	i = 0;
	while(map.map[i])
	{
		ft_printf("%s$\n", map.map[i]);
		i++;
	}
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1920, 1080, "so_long");
	mlx_loop(data.mlx);
	pause();
}
