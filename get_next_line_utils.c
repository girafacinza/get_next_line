#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned long i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s1_cpy;
	size_t	len;
	size_t	i;

	len = ft_strlen((char *)s1);
	i = 0;
	if (!(s1_cpy = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (i < len)
	{
		*(s1_cpy + i) = *(s1 + i);
		i++;
	}
	*(s1_cpy + i) = '\0';
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
