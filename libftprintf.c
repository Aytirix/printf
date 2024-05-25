/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmouty <thmouty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 02:34:34 by thmouty           #+#    #+#             */
/*   Updated: 2024/04/30 02:34:34 by thmouty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar_fd(char c, int fd, int *count)
{
	*count += write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd, int *count)
{
	if (!s)
		return (ft_putstr_fd("(null)", 1, count));
	while (*s)
		ft_putchar_fd(*s++, fd, count);
}

void	ft_putnbr_base_fd(long long nb, char *base, int fd, int *count)
{
	long long	baselen;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd, count);
		nb = nb * -1;
	}
	baselen = ft_strlen(base);
	if (nb >= baselen)
		ft_putnbr_base_fd(nb / baselen, base, fd, count);
	ft_putchar_fd(base[nb % baselen], fd, count);
}

void	ft_putunbr_base_fd(unsigned long long nb, char *base, int fd,
		int *count)
{
	unsigned long long	baselen;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd, count);
		nb = nb * -1;
	}
	baselen = ft_strlen(base);
	if (nb >= baselen)
		ft_putunbr_base_fd(nb / baselen, base, fd, count);
	ft_putchar_fd(base[nb % baselen], fd, count);
}
