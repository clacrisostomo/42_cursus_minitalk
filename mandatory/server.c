/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 22:44:12 by csantos-          #+#    #+#             */
/*   Updated: 2021/07/25 16:45:36 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	receive_message(int num_bit, pid_t id_client)
{
	static int	str;
	static int	in_bits;
	static char	buffer[1000];
	static int	len;

	str = str << 1 | num_bit;
	if (++in_bits == 8)
	{
		buffer[len++] = str;
		if (str == '\0' || len >= 1000)
		{
			write(1, buffer, (len - (str == '\0')));
			write(1, "\n", 1);
			len = 0;
			if (str == '\0')
				kill(id_client, SIGUSR1);
		}
		str = 0;
		in_bits = 0;
	}
}

void	sig_action(int signum, siginfo_t *info, void *ucontext)
{
	(void)signum;
	(void)ucontext;
	receive_message(signum == SIGUSR2, info->si_pid);
}

int	setup_handlers(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = sig_action;
	if (sigemptyset(&act.sa_mask) < 0
		|| sigaction(SIGUSR1, &act, NULL) < 0
		|| sigaction(SIGUSR2, &act, NULL) < 0)
		return (-1);
	return (0);
}

void	print_id(pid_t id)
{
	char	char_id;

	if (!id)
		return ;
	print_id(id / 10);
	char_id = (id % 10) + '0';
	write(1, &char_id, 1);
}

int	main(int argc, char **argv)
{
	pid_t	id;

	if (argc != 1)
	{
		write(1, "Error: too many arguments.", 26);
		write(1, "Try typing: ./server", 20);
		return (-1);
	}
	if (setup_handlers() == -1)
		return (1);
	id = getpid();
	write(1, "Use this ID number to send your message:", 40);
	print_id(id);
	write(1, "\n", 1);
	while (1)
		pause();
	(void)argv;
	return (0);
}
