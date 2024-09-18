void	*ft_memmove(void	*dst, const	void	*src, size_t	len)
{
	size_t	i;

	i = 0;
	if (dst == src)
		return (dst);
	if (dst < src)
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
			i++;
		}
	else
		while (len > 0)
		{
			len--;
			((unsigned char *)dst)[len] = ((const unsigned char *)src)[len];
		}
	}
	return (dst);
}
