/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lambrozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 19:30:15 by lambrozi          #+#    #+#             */
/*   Updated: 2020/02/12 20:03:04 by lambrozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>


/*
void	ft_get_numbers(char *buf)
{
	int		size;
	int		j;
	int		k;
	int		i;

	size = size_dict(buf);
	j = 0;
	i = 0;
	while (buf[i] != '\0')
	{
		k = 0;
		while (buf[i] != ' ' && buf[i] != ':')
		{
			g_numbs[j].nbr[k] = buf[i];
			i++;
			k++;
		}
		g_numbs[j].nbr[k] = '\0';
		g_numbs[j].digits = k;
		while (buf[i] == ' ' || buf[i] == ':')
			i++;
		k = 0;
		while (buf[i] != '\n' && *(buf + 1) != '\0')
		{
			g_numbs[j].text[k] = buf[i];
			i++;
			k++;
		}
		g_numbs[j].text[k] = '\0';
		j++;
		i++;
	}
	j = 0;
}

int		ft_read_file(char *name)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE];

	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Cannot open file.\n");
		return (0);
	}
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (close(fd) == -1)
	{
		ft_putstr("Cannot close file.\n");
		return (0);
	}
	ft_get_numbers(buf);
	return (1);
}
*/
int		get_next_line(int fd, char **line)
{
	char	*buf;
	static int	ret;
	int	i;

	if (fd == -1)
		return (-1);
	i = -1;
	buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
	while ((ret = read(fd, &buf[++i], 1)))
	{
	//	printf("[buf(%d)=%c]", i, buf[i]);		
		if (buf[i] == '\n')
		{
			buf[i + 1] = '\0';
			//printf("%s", buf);
			*line = buf;
			free(buf);
			return (1);
		}
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int	fd;
	char	*str;

	(void)argv;
	if (argc == 1)
		fd = open("teste.txt", O_RDONLY);
	else
		fd = 0;
	if (fd == -1)
		return (-1);
	while (get_next_line(fd, &str))
		printf("%s", str);
	if (close(fd) == -1)
		return (-1);
	return (0);
}

