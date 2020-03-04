/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lambrozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:30:15 by lambrozi          #+#    #+#             */
/*   Updated: 2020/03/03 21:51:17 by lambrozi         ###   ########.fr       */
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


char		*refreshheap(char *heap, char *buff)
{
	char *temp;

	if (!heap)
	{
		heap = ft_strdup(buff);
		return (heap);
	}
	temp = ft_strjoin(heap, buff);
	free(heap);
	heap = ft_strdup(temp);
	return (heap);
}

int		get_next_line(int fd, char **line)
{
	static char	*heap;
	static int	ret;
	char		buff[BUFFER_SIZE + 1];
	int		i;

	i = newline(heap);
	if (heap && i >= 0) //tem \n no heap
	{
//		printf("[n posit:%d]", i);
		*line = ft_substr(heap, 0, i);
		heap = ft_strdup(&heap[i + 1]); //leak de memoria
//		printf("[buff][line:%s][heap:%s]\n", *line, heap);
		return (1);
	}
	ret = read(fd, buff, BUFFER_SIZE);
	buff[ret] = '\0';
//	printf("[buff=%s][heap=%s]", buff, heap);
	i = newline(buff);
	if (i >= 0) //tem \n no buff
	{
		heap = refreshheap(heap, ft_substr(buff, 0, i));
		*line = ft_strdup(heap);
		free(heap);
		heap = ft_strdup(&buff[i + 1]);
//		printf("[line:%s][heap:%s]\n", *line, heap);
		return (1);
	}
	if (ret && i == -1) //fd nao acabou e buff nao tem \n
	{
		heap = refreshheap(heap, buff);
		return (get_next_line(fd, line));
	}
	*line = ft_strdup(heap);
	free(heap);
	return (0);	
}

int		main(int argc, char **argv)
{
	int	fd;
	char	*str;
//	int	i = 1;

	(void)argv;
	if (argc == 1)
		fd = open("teste.txt", O_RDONLY);
	else
		fd = 1;
	if (fd == -1)
		return (-1);
	while (get_next_line(fd, &str))
	{
//		printf("l%d:[[%s]]\n\n", i++, str);
		printf("%s\n", str);
	}
	if (close(fd) == -1)
		return (-1);
	return (0);
}

