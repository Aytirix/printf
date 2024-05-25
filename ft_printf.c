/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 17:25:25 by thmouty           #+#    #+#             */
/*   Updated: 2024/04/30 02:44:35 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putaddress(unsigned long long address, int fd, int *count)
{
	if (!address)
		return (ft_putstr_fd("(nil)", fd, count));
	ft_putstr_fd("0x", 1, count);
	if (address == -1ULL)
		return (ft_putstr_fd("ffffffffffffffff", fd, count));
	ft_putunbr_base_fd(address, "0123456789abcdef", fd, count);
}

static void	checker(const char *str, va_list args, int fd, int *count)
{
	if (*str == 'c')
		ft_putchar_fd(va_arg(args, int), fd, count);
	else if (*str == 's')
		ft_putstr_fd(va_arg(args, char *), fd, count);
	else if (*str == 'p')
		ft_putaddress(va_arg(args, long long), fd, count);
	else if (*str == 'd' || *str == 'i')
		ft_putnbr_base_fd(va_arg(args, int), "0123456789", fd, count);
	else if (*str == 'u')
		ft_putnbr_base_fd(va_arg(args, unsigned int), "0123456789", fd, count);
	else if (*str == 'x')
		ft_putunbr_base_fd(va_arg(args, unsigned int), "0123456789abcdef", fd,
			count);
	else if (*str == 'X')
		ft_putunbr_base_fd(va_arg(args, unsigned int), "0123456789ABCDEF", fd,
			count);
	else if (*str == '%')
		ft_putstr_fd("%", 1, count);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	args;

	count = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			checker(++str, args, STDOUT_FILENO, &count);
		else
			ft_putchar_fd(*str, 1, &count);
		str++;
	}
	va_end(args);
	return (count);
}
