#include "get_next_line.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

char	*leggiriga(char *saved, int fd)
{
	int		i;
	char	*temp;

	temp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	temp = ft_memset(temp, 0, (BUFFER_SIZE + 1));
	i = 1;
	while (!ft_strchr(temp, '\n') && i > 0)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i < 0)
			return (free(temp), NULL);
		temp[i] = '\0';
		if (!saved)
			saved = ft_strdup(temp);
		else
			saved = ft_strjoin(saved, temp);
		if (!saved)
			return (NULL);
	}
	if (i == 0 && (!saved || saved[0] == '\0'))
		return (free(saved), free(temp), NULL);
	free(temp);
	return (saved);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*line;
	char		*temp;
	int			i;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	saved = leggiriga(saved, fd);
	if (!saved)
		return (NULL);
	i = 0;
	while (saved[i] != '\n' && saved[i])
		i++;
	if (saved[i] == '\n')
		i++;
	line = ft_substr(saved, 0, i);
	temp = ft_substr(saved, i, ft_strlen(saved) - i);
	free (saved);
	saved = temp;
	return (line);
}
/*
int main(void)
{
    int     fd;
    char    *linea = NULL;
    int j = 0;

    fd = open("prova.txt", O_RDONLY);
    if (fd < 0)
    {
       	printf("Errore nell'apertura del file");
       	return (1);
    }
    while (j < 15)
    {
    	linea = get_next_line(fd);
        printf("%s", linea);
        free(linea);
        j++;
    }

	close(fd);
	return (0);
}
*/
