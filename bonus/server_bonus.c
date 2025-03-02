/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhammiou <hhammiou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:54:23 by hhammiou          #+#    #+#             */
/*   Updated: 2025/03/01 13:45:43 by hhammiou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header_bonus.h"

void	send_char(char c, int pid)
{
	if (c == '\0')
	{
		write(1, "\n", 1);
		kill(pid, SIGUSR1);
	}
	else
		write(1, &c, 1);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static char	character;
	static int	bit_count;
	static int	client_pid;

	if (client_pid != info->si_pid)
	{
		bit_count = 0;
		character = 0;
		client_pid = info->si_pid;
	}
	(void)context;
	if (signum == SIGUSR1)
		character = character << 1 | 0;
	else if (signum == SIGUSR2)
		character = character << 1 | 1;
	bit_count++;
	if (bit_count == 8)
	{
		send_char(character, client_pid);
		bit_count = 0;
		character = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sg;

	(void)av;
	if (ac != 1)
		ft_msg_error("\033[1;31mError : Invalid arguments !\n\033[0m");
	sg.sa_sigaction = &signal_handler;
	sg.sa_flags = SA_SIGINFO;
	sigemptyset(&sg.sa_mask);
	sigaction(SIGUSR1, &sg, NULL);
	sigaction(SIGUSR2, &sg, NULL);
	mini_printf(1, "Server (PID): \033[1;32m%d\n\033[0m", getpid());
	mini_printf(1, "Waiting for messages...\n");
	while (1)
		pause();
	return (0);
}
