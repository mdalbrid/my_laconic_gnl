#include "get_next_line.h"

#include <stdlib.h>

void	ft_memdel(void **ap)
{
	if (ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}

void	ft_strdel(char **as)
{
	ft_memdel((void**)as);
}

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		ret;

	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	line = NULL;
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &line);
		printf("%s\treturn value - %d\n", line, ret);
		ft_strdel(&line);
	}
	close(fd);
	// while (1);  //for check on leaks (leaks a.out)
}
