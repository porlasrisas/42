static int	ft_isalpha(int	c)
{
	if(!(c >= 65 && c <= 90 || c >= 97 && c <= 122))
		return (0);
	else
		return (1);
}
static int	ft_isdigit(int	c)
{
	if(!(c >= 48  && c <= 57))
		return (0);
	else
		return (1);
}
int	ft_isalnum(int	c)
{
	if(ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return(0);
}
