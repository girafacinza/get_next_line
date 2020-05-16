#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int	fd;
	char	*str;
	int	i = 1;

	(void)argv;
	if (argc == 1)
		fd = open("./tests/long_line.txt", O_RDONLY);
	else
		fd = 1;
	if (fd == -1)
		return (-1);
	while (get_next_line(fd, &str))
	{
		printf("l%d:%s\n", i++, str);
//		printf("%s\n", str);
	}
	printf("l%d:%s\n", i++, str);
	if (close(fd) == -1)
		return (-1);
	return (0);
}