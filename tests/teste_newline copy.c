#include <stdio.h>
#include <fcntl.h>

int		newline(const char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	main(void)
{
	printf("%d", newline("a\n"));
	return (0);
}
