size_t ft_strlcat(char	*dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	aux_len;

	i = 0;
	j = 0;
	aux_len = 0;
	while(dst[i] != '\0' && i < dstsize	)
		i++;
	while(src[j] != '\0')
		j++;
	if(dstsize == 0 || i >= dstsize)
		return (dstsize + j);
	while(src[aux_len] != '\0' && i + aux_len < dstsize - 1)
	{
		dst[aux_len + i] = src[aux_len];
		aux_len++;
	}
	if(i + aux_len < dstsize)
		dst[i + aux_len] = '\0';
	return (i + j);
}
