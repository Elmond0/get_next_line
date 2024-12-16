 #include "get_next_line.h"
 
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
