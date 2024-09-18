size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	aux_len;

	i = 0;
	aux_len = 0;
	while(src[i] != '\0')
		i++;
	if(dstsize == 0)
		return (i);
	while(src[aux_len] != '\0' && aux_len < dstsize - 1)
	{
		dst[aux_len] = src[aux_len];
		aux_len++;
	}
	dst[aux_len] = '\0';
	return (i);
}
