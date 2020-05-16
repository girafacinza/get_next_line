#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	unsigned long i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(const char *str1, const char *str2)
{
	char	*str;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(str1);
	len += ft_strlen(str2);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (*str1)
		*str++ = *str1++;
	while (*str2)
		*str++ = *str2++;
	*str = '\0';
	return (&(*(str - len)));
}

int	main(void)
{
	char *str;

	str = ft_strjoin("eu amo ","voce!");
	printf("%s\n", str);
	return (0);
}
