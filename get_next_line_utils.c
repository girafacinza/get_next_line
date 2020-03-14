/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lambrozi <lambrozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 19:22:28 by lambrozi          #+#    #+#             */
/*   Updated: 2020/03/10 21:40:04 by lambrozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	unsigned long i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s1, int init)
{
	char	*s1_cpy;
	int	len;
	int	i;

	i = 0;
	len = ft_strlen((char *)s1);
	if (!(s1_cpy = (char *)malloc((len - init + 1) * sizeof(char))))
		return (NULL);
	while (i + init < len)
	{
		*(s1_cpy + i) = *(s1 + init + i);
		i++;
	}
	*(s1_cpy + i) = '\0';
	free(s1);
	return (s1_cpy);
}

char	*ft_substr(const char *s, int start, int len)
{
	char	*str;
	int	i;
	int	s_len;

	if (!s)
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	while ((i < len) && (start + i) < s_len)
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*str;
	int	len;
	int	i;

	i = 0;
	if (!str1)
	{
		str = ft_strdup(str2, 0);
		return (str);
	}
	len = ft_strlen(str1);
	len += ft_strlen(str2);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*(str1 + i))
		*str++ = *(str1 + i++);
	i = 0;
	while (*(str2 + i))
		*str++ = *(str2 + i++);
	*str = '\0';
	free(str1);
	free(str2);
	return (&(*(str - len)));
}
