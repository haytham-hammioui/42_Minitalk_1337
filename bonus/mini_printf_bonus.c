/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_printf_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 11:51:53 by hhammiou          #+#    #+#             */
/*   Updated: 2025/03/01 16:03:44 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

static void	ft_putchar(int fd, char c)
{
	write(fd, &c, 1);
}

static void	ft_putstr(int fd, char *str)
{
	while (*str)
	{
		ft_putchar(fd, *str);
		str++;
	}
}

static void	ft_putnbr(int fd, int nbr)
{
	long int	n;

	n = nbr;
	if (n < 0)
	{
		ft_putchar(fd, '-');
		n = -n;
	}
	if (n > 9)
		ft_putnbr(fd, n / 10);
	ft_putchar(fd, (n % 10) + '0');
}

void	mini_printf(int fd, const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			else if (*format == 's')
				ft_putstr(fd, va_arg(args, char *));
			else if (*format == 'd')
				ft_putnbr(fd, va_arg(args, int));
			else if (*format == 'c')
				ft_putchar(fd, (char)va_arg(args, int));
		}
		else
			ft_putchar(fd, *format);
		format++;
	}
	va_end(args);
}
