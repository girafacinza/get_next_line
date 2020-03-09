/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lambrozi <lambrozi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:56:51 by lambrozi          #+#    #+#             */
/*   Updated: 2020/03/09 19:26:49 by lambrozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned long i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char **s1)
{
	char	*s1_cpy;
	size_t	len;
	size_t	i;

	if (!s1)
		return (NULL);
	len = ft_strlen(*s1);
	i = 0;
	if (!(s1_cpy = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (i < len)
	{
		*(s1_cpy + i) = *(s1[i]);
		i++;
	}
	*(s1_cpy + i) = '\0';
	free(*s1);
	return (s1_cpy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

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

char	*ft_strjoin(char **str1, char **str2)
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	if (!*str1)
		return (ft_strdup(str2));
	len = ft_strlen(*str1);
	len += ft_strlen(*str2);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (**str1)
		*str++ = **str1++;
	while (**str2)
		*str++ = **str2++;
	*str = '\0';
	free(*str1);
	free(*str2);
	return (&(*(str - len)));
}
