#include "get_next_line.h"

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
/*
int	main()
{
	char *s = "ipouille";
 	//size_t size = strlen(s);
 	char *ret = ft_substr("tripouille", 2, 42000);
 	if (!strcmp(s, ret))
	{
 		printf("TEST_SUCCESS");
 		printf("%s", ret);
 		return 0;
 	}
 	free(ret);
 	printf("TEST_FAILED");
 	return(0);
}
*/
