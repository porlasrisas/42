/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guigonza <guigonza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:42:19 by guigonza          #+#    #+#             */
/*   Updated: 2025/01/09 17:29:26 by guigonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <ctype.h>
# include <limits.h>

int		ft_printf(const char *formart, ...);
int		ft_putchar_fd_p(char c, int fd);
int		ft_putstr_fd_p(char *s, int fd);
int		ft_putnbr_fd_p(int n, int fd);
int		ft_putnbr_hex(unsigned long n, int uppercase);

#endif