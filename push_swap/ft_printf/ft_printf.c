/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:50:31 by guigonza          #+#    #+#             */
/*   Updated: 2025/01/09 17:34:08 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_unsigned(unsigned int n, int fd)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putnbr_unsigned(n / 10, fd);
	count += ft_putchar_fd_p((n % 10) + '0', fd);
	return (count);
}

static int	ft_print_pointer(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_putstr_fd_p("(nil)", 1));
	count += ft_putstr_fd_p("0x", 1);
	count += ft_putnbr_hex((unsigned long)ptr, 0);
	return (count);
}

static int	ft_conversion(char del, va_list args)
{
	int	printed;

	printed = 0;
	if (del == 'c')
		printed += ft_putchar_fd_p((char)va_arg(args, int), 1);
	else if (del == 's')
		printed += ft_putstr_fd_p(va_arg(args, char *), 1);
	if (del == 'd' || del == 'i')
		printed += ft_putnbr_fd_p(va_arg(args, int), 1);
	else if (del == 'u')
		printed += ft_putnbr_unsigned(va_arg(args, unsigned int), 1);
	if (del == '%')
		printed += ft_putchar_fd_p('%', 1);
	if (del == 'p')
		printed += ft_print_pointer(va_arg(args, void *));
	if (del == 'x')
		printed += ft_putnbr_hex(va_arg(args, unsigned int), 0);
	else if (del == 'X')
		printed += ft_putnbr_hex(va_arg(args, unsigned int), 1);
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed;
	int		i;

	va_start(args, format);
	printed = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			printed += ft_conversion(format[i], args);
		}
		else
		{
			printed += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (printed);
}
