#include "so_long.h"

void	checkfile(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
	{
		ft_printf("Error: too few arguments...\n");
		exit(0);
	}
	else if (argc > 2)
	{
		ft_printf("Error: too many arguments...\n");
		exit(0);
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
		{
			ft_printf("Error: can't find file with name \"%s\"...\n", argv[1]);
			exit(0);
		}
		close(fd);
	}
}
