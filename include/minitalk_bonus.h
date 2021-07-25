/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 20:32:35 by csantos-          #+#    #+#             */
/*   Updated: 2021/07/25 16:24:52 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

int	g_mess_received;

/**
* SERVER
**/

void	print_id(pid_t id);
int		setup_handlers(void);
void	sig_action(int signum, siginfo_t *info, void *ucontext);
void	receive_message(int num_bit, pid_t id_client);

/**
 *CLIENT
**/

pid_t	get_numid(char *arg);
int		send_message(char *arg, pid_t num_id);
void	check_message(int signum);

#endif