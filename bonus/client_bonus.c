/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 16:00:53 by csantos-          #+#    #+#             */
/*   Updated: 2021/07/25 17:30:03 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

int	send_message(char *arg, pid_t num_id)
{
	int	i;
	int	in_bits;
	int	bit;

	i = 0;
	while (1)
	{
		bit = 7;
		while (bit >= 0)
		{
			in_bits = (arg[i] & (1 << bit));
			if (kill(num_id, (int []){SIGUSR1, SIGUSR2}[in_bits > 0]) < 0)
				return (1);
			if (usleep(100) == -1)
				return (-1);
			bit--;
		}
		if (arg[i] == '\0')
			break ;
		i++;
	}
	return (0);
}

void	check_message(int signum)
{
	(void)signum;
	g_mess_received = 1;
	write(1, "Your message was sent successfully!\n", 36);
}

pid_t	get_numid(char *arg)
{
	int	num;

	num = 0;
	while (*arg)
	{
		if (*arg >= 0 && *arg <= '9')
			num = (num * 10) + *arg - '0';
		else
			return (-1);
		arg++;
	}
	return (num);
}

int	main(int argc, char **argv)
{
	pid_t	num_id;

	if (argc != 3)
	{
		write(1, "Error: Invalid number of arguments.\n", 36);
		write(1, "Try: ./client_server + ID number + message\n", 43);
		return (1);
	}
	num_id = get_numid(argv[1]);
	if (num_id <= 1)
	{
		write(1, "Error: Invalid server ID number.\n", 33);
		return (2);
	}
	g_mess_received = 0;
	if (signal(SIGUSR1, check_message) == SIG_ERR
		|| send_message(argv[2], num_id) != 0)
		return (1);
	if (g_mess_received == 0)
		sleep(5);
	if (g_mess_received == 1)
		return (0);
	write(1, "Error: Unable to connect with server.\n", 38);
	return (1);
}
