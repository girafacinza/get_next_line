/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lambrozi <lambrozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:30:15 by lambrozi          #+#    #+#             */
/*   Updated: 2020/03/09 19:16:13 by lambrozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		newline(const char *str)
{
	int i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static char	*heap;
	static int	ret;
	char		*buff;
	int			i;

	if (fd < 0 || fd == 1 || fd == 2)
		return (-1);
	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	ret = read(fd, buff, BUFFER_SIZE);
	buff[ret] = '\0';
	heap = ft_strjoin(&heap, &buff);
	i = newline(heap);
	printf(".");
	if (heap && i >= 0) //tem \n no heap
	{
		*line = ft_substr(heap, 0, i);
		heap = ft_strdup(&(heap)+ i + 1);
		if (ret == 0 && *heap == '\0')
		{
			free(heap);
			return (0);
		}
		return (1);
	}
	if (ret != 0) //fd nao acabou e buff nao tem \n
		return (get_next_line(fd, line));
	if (heap)
		*line = ft_strdup(&heap);
	return (0);	
}

int		main(int argc, char **argv)
{
	int	fd;
	char	*str;
	int	i = 0;

	(void)argv;
	if (argc == 1)
		fd = open("teste.txt", O_RDONLY);
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
