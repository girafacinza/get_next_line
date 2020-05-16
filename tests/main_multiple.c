#include "get_next_line.h"
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
	char	*st;
	int		i;
	int		i2;

	st = NULL;
	i = 1;
	i2 = 1;
	doprint(get_next_line(fd, &st), &st, i++);		//1,1
	doprint(get_next_line(fd2, &st), &st, i2++);	//1,2
	doprint(get_next_line(fd2, &st), &st, i2++);	//2,2
	doprint(get_next_line(fd, &st), &st, i++);		//2,1
	doprint(get_next_line(fd, &st), &st, i++);		//3,1
	doprint(get_next_line(fd2, &st), &st, i2++);	//3,2
	doprint(get_next_line(fd, &st), &st, i++);		//4,1
	doprint(get_next_line(fd2, &st), &st, i2++);	//4,2
	doprint(get_next_line(fd2, &st), &st, i2++);	//5,2
	doprint(get_next_line(fd, &st), &st, i++);		//5,1
	doprint(get_next_line(fd2, &st), &st, i2++);	//6,2
	doprint(get_next_line(fd, &st), &st, i++);		//6,1
	doprint(get_next_line(fd2, &st), &st, i2++);	//7,2
	doprint(get_next_line(fd2, &st), &st, i2++);	//8,2
	doprint(get_next_line(fd, &st), &st, i++);		//7,1
	doprint(get_next_line(fd, &st), &st, i++);		//8,1
	doprint(get_next_line(fd, &st), &st, i++);		//9,1
	doprint(get_next_line(fd, &st), &st, i++);		//10,1
	close(fd);
	close(fd2);
}

int		main(int argc, char **argv)
{
	int	fd;
	int	fd2;

	(void)argv;
	if (argc == 1)
		fd = open("./tests/teste1.txt", O_RDONLY);
	else if (argc == 3)
	{
		fd = open(argv[1], O_RDONLY);
		fd2 = open(argv[2], O_RDONLY);
		testmultiple(fd, fd2);
	}
	else
		fd = 1;
	if (fd == -1)
		return (-1);
/*
	while (get_next_line(fd, &str))
	{
		printf("l%d:%s\n", i++, str);
//		printf("%s\n", str);
	}
	printf("l%d:%s\n", i++, str);
	if (close(fd) == -1)
		return (-1);
*/
	return (0);
}