#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	
	ch = (char)c;
	while (*s)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*str;
	
	len = ft_strlen(s);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < len1)
		str[i] = s1[i];
	while (++j < len2)
		str[i + j] = s2[j];
	str[i + j] = '\0';
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;
	
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int	i;
	int	j;
	char	*str;
	size_t	max_len;
	
	i = 0;
	j = 0;
	if (start >= ft_strlen(s))
		return(ft_strdup(""));
	max_len = ft_strlen(s) - start;
	if (max_len > len)
		max_len = len;
	str = (char *)malloc(sizeof(char) * (max_len + 1));
	if (!str)
		return (NULL);
	while (s[i] && i < (char)start)
		i++;
	while (j < (int)(max_len))
	{
		str[j] = s[i + j];
		j++;
	}
	str[j] = 0;
	return (str);
}
