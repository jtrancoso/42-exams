#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int i;
	
	i = 0;
	while(*s)
	{
		s++;
		i++;
	}
	return(i);
}

char *ft_strchr(char *s, int c)
{
	char *aux;

	if (!s)
		return (NULL);
	aux = s;
	while (*aux != c)
	{
		if (*aux == '\0')
			return (NULL);
		aux++;
	}
	return (aux);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *aux;
	int i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	if (!(aux = malloc(sizeof(char *) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (*s1)
	{
		aux[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		aux[i] = *s2;
		i++;
		s2++;
	}
	aux[i] = '\0';
	return (aux);
}

char *ft_strdup(char *s)
{
	char *aux;
	int i;
	int j;

	if (!s)
		return (NULL);
	if (!(aux = malloc(sizeof(char *) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		aux[j] = s[i];
		i++;
		j++;
	}
	aux[i] = '\0';
	return (aux);
}


int get_next_line(char **line)
{
	static char *mem;
	char buffer[256];
	char *aux, *s1, *s2;
	int bread;

	if (!line)
		return (-1);
	while (!(ft_strchr(mem, '\n')))
	{
		bread = read(0, buffer, 255);
		if (bread < 0)
			return (-1);
		if (bread == 0)
			break ;
		buffer[bread] = '\0';
		if (!mem)
			mem = ft_strdup(mem);
		else
		{
			aux = ft_strjoin(mem, buffer);
			free (mem);
			mem = aux;
		}
	}
	if (!mem && !bread)
	{
		*line = ft_strdup("");
		return (0);
	}
	else if ((s1 = ft_strchr(mem, '\0')))
	{
		*s1 = 0;
		*line = ft_strdup(mem);
		*s2 = ft_strdup(++s1);
		free (mem);
		mem = s2;
	}
	else
	{
		*line = ft_strdup(mem);
		free(mem);
		mem = NULL;
	}
	return (1);
	
}

/*int main (void)
{
	char s1[100] = "123";
	char s2[100] = "los microfonos";
	
	printf("%s\n", ft_strjoin(s1, s2));
	printf("%s\n", ft_strdup(s2));
	printf("%d\n", ft_strlen(s1));
	printf("%s\n", ft_strchr(s2, 'f'));
}*/