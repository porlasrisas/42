#include <limits.h>
int	ft_atoi(const char	*str)
{
	int	i;
	int	sign;
	long long	result;
	i = 0;
	sign = 1;
	result = 0;
	while((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
	if(str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		if(result > (INT_MAX - (str[i] - '0')) / 10)
		{
			if(sign == 1)
				return(INT_MAX);
			else
				return (INT_MIN);
		}
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(result * sign));
}
