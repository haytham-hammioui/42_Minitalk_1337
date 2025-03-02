/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 22:20:08 by hhammiou          #+#    #+#             */
/*   Updated: 2025/03/01 16:01:48 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_msg_error(char *msg)
{
	mini_printf(2, "%s", msg);
	exit(1);
}

int	ft_atoi2(const char *str, int s)
{
	unsigned long long	r;
	int					i;

	r = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + (str[i] - '0');
		if ((long long)(r * s) > INT_MAX || (long long)(r * s) < INT_MIN)
			ft_msg_error("\033[1;31mError : Invalid PID !\n\033[0m");
		i++;
	}
	if (str[i])
		ft_msg_error("\033[1;31mError : Invalid PID !\n\033[0m");
	return ((int)(r * s));
}

int	ft_atoi(const char *str)
{
	int					i;
	int					s;

	i = 0;
	s = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	return (ft_atoi2(&str[i], s));
}
