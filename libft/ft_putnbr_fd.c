#include "libft.h"

void	ft_putnbr_fd(int	n, int	fd)
{
	long	copy;

	copy = n;
	if (copy < 0)
	{
		copy = (copy * -1);
		ft_putchar_fd("-", fd);
	}
	if (copy > 9)
	{
		ft_putnbr_fd(copy /  10, fd);
		ft_putchar_fd((copy % 10) + '0', fd);
	}
	else
		ft_putchar_fd(copy + '0', fd);
}
