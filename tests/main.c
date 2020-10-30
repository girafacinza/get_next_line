#include "../srcs/get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	doprint(int out, char **str, int line)
{
	printf("(LINE %i) [OUT %i] |%s|\n", line, out, *str);
	free(*str);
	*str = NULL;
}

void	testmultiple(int fd, int fd2)
{
	char	*str1=NULL;
	char	*str2=NULL;
	int		i = 1;
	int		i2 = 1;
	int		fim1 = 0;
	int		fim2 = 0;

	while (fim1 + fim2 < 2)
	{
		if (get_next_line(fd, &str1) != 0)
			printf("[F1-L%03d]:%s\n", i++, str1);
		else
			fim1 = 1;
		if (get_next_line(fd2, &str2) != 0)
			printf("[F2-L%03d]:%s\n", i2++, str2);
		else
			fim2 = 1;
	}
	printf("[F1-L%03d]:%s\n", i++, str1);
	printf("[F2-L%03d]:%s\n", i2++, str2);
	close(fd);
	close(fd2);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	char	*str;
	int		i = 1;

	(void)argv;
	if (argc == 1 || argc == 2)
	{
		if (argc == 1)
			fd = 1;
		else
			fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (-1);
		while (get_next_line(fd, &str))
			printf("[L%03d]:%s\n", i++, str);
		printf("[L%03d]:%s\n", i++, str);
		if (close(fd) == -1)
			return (-1);
	}
	else if (argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		testmultiple(fd, fd2);
		return (0);
	}
	return (0);
}