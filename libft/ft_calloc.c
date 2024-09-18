#include <stdlib.h>

static void	*ft_memset(void	*b, int	c, size_t	len)
{
	size_t	i;

	i = 0;
	while(i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return(b);
}
void	*calloc(size_t	count, size_t	size)
{
	size_t	total_size;
	void	*ptr;

	total_size = count * size;
	ptr = malloc(total_size);
	if(ptr == NULL)
		return(NULL);
	ft_memset(ptr, 0, total_size);
	return (ptr);
}
