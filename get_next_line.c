#include "get_next_line.h"

char	*leggiriga(char *buffer, int fd)
{
	long	i;
	char	temp[BUFFER_SIZE + 1];
	
	i = -1;
	while (++i <= BUFFER_SIZE)
		temp[i] = '\0';
	i = 1;
	while (!ft_strchr(temp, '\n'))
	{
		i = read(fd, temp, BUFFER_SIZE);
		if (i < 0 || (!i && !buffer))
			return (NULL);
		temp[i] = '\0';
		if (!buffer)
			buffer = ft_strdup(temp);
		else
			buffer = ft_strjoin(buffer, temp);
		if (!buffer)
			return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*linea;
	//char		*temp;
	size_t	i;
	
	buffer = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buffer = leggiriga(buffer, fd);
	i = 0;
	while (buffer[i] != '\n')
		i++;
	i++;
	buffer[i] = '\n';
	linea = ft_substr(buffer, 0, i);
	return (linea);
}

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
    	//printf("fd: %d", fd);
	linea = get_next_line(fd);
	//printf("linea: %s\n", linea);
    // Leggiamo il file riga per riga fino alla fine (get_next_line ritorna NULL)
	if (linea != NULL)
    	{
        	printf("%s", linea);
        	free(linea);
    	}
	close(fd);
	return (0);
}
