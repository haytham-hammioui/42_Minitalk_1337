/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:01:37 by hhammiou          #+#    #+#             */
/*   Updated: 2025/03/01 16:02:32 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	send_bit(int pid, char bit)
{
	int	check;

	if (bit == '0')
		check = kill(pid, SIGUSR1);
	else
		check = kill(pid, SIGUSR2);
	usleep(100);
	return (check);
}

void	send_null(int pid)
{
	int	bit;

	bit = 7;
	while (bit >= 0)
	{
		send_bit(pid, '0');
		bit--;
	}
}

void	ft_send_message(int s_pid, char *message)
{
	int		bit_count;
	int		check;
	int		i;

	i = 0;
	while (message[i])
	{
		bit_count = 7;
		while (bit_count >= 0)
		{
			if (message[i] & (1 << bit_count))
				check = send_bit(s_pid, '1');
			else
				check = send_bit(s_pid, '0');
			if (check == -1)
				ft_msg_error("\033[1;31mError : Invalid PID !\n\033[0m");
			usleep(500);
			bit_count--;
		}
		i++;
	}
	send_null(s_pid);
}

int	main(int ac, char **av)
{
	int	server_pid;

	if (ac != 3)
		ft_msg_error("\033[1;31mError : Invalid arguments !\n\033[0m");
	server_pid = ft_atoi(av[1]);
	if (server_pid <= 0)
		ft_msg_error("\033[1;31mError : Invalid PID !\n\033[0m");
	mini_printf(1, "\033[1;33mSending message to PID : %d ...\033[0m\n",
		server_pid);
	ft_send_message(server_pid, av[2]);
	return (0);
}
