#include "libft.h"

static void	ft_free(char  **s, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static size_t	ft_count_words(const char *s, char c)
{
	size_t	count;
	size_t	word;
	size_t	i;

	count = 0;
	word = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && word == 0)
		{
			word = 1;
			count++;
			i++;
		}
		else if (s[i] == c)
			word = 0;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	start;
	size_t	i;
	size_t	j;
	char	**result;

	i  = 0;
	j  = 0;
	if (!s || !(result = ft_calloc(ft_count_words(s, c) + 1, sizeof(char *))))
			return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			result[j] = ft_substr(s, start, i - start);
			if (!result[j++])
				return (ft_free(result, j - 1), NULL);
		}
		else
			i++;
	}
	result[j] = NULL;
	return (result);
}
