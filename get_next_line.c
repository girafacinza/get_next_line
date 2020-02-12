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
int		get_next_line(int fd, char **line)
{
	char	*buf;
	int		ret;

	if (fd == -1)
		return (-1);
	
}
