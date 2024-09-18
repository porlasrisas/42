#include <stdlib.h>

static size_t	ft_strlen(const	char	*s)
{
	size_t	i;

	i = 0;
	while(s[i] != '\0')
	{
		i++;
	}
	return (i);
}
char	*ft_strjoin(char const	*s1, char const	*s2)
{
	size_t	i;
	size_t	j;
	char	*result;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL)
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}
