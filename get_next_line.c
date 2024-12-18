#include "get_next_line.h"


char	*leggiriga(char *saved, int fd)
{
	long	i;
	char	temp[BUFFER_SIZE + 1];
	
	
	i = -1;
	while (++i <= BUFFER_SIZE)
		temp[i] = '\0';
	i = 1;
	while (!ft_strchr(temp, '\n') && i)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i < 0 || (!i && !saved))
			return (NULL);
		temp[i] = '\0';
		if (i == 0)
		{
			if (*saved == '\0')
				return (NULL); // Fine del file, nessun contenuto
			break;
		}
		if (!saved)
			saved = ft_strdup(temp);
		else
			saved = ft_strjoin(saved, temp);
		if (!saved)
			return (NULL);
	}
	return (saved);
}

char	*get_next_line(int fd)
{
	static char	*saved;
	char		*linea;
	char		*temp;
	int	i;
	
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	saved = leggiriga(saved, fd);
	if(!saved)
		return (NULL);
	i = 0;
	while (saved[i] != '\n' && saved[i])
		i++;
	if (saved[i] == '\n')
		i++;
	linea = ft_substr(saved, 0, i);
	temp = ft_substr(saved, i, ft_strlen(saved) - i);
	free (saved);
	saved = temp;
	return (linea);
}
/*
int main(void)
{
    	int     fd;
    	char    *linea = ft_strdup("");

    	fd = open("prova.txt", O_RDONLY);
    	if (fd < 0)
    	{
        	printf("Errore nell'apertura del file");
        	return (1);
    	}
    	  while ((linea = get_next_line(fd)) != NULL)
    {
        printf("%s", linea);
        free(linea);
    }

	close(fd);
	return (0);
}
*/
