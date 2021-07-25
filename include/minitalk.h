/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csantos- <csantos-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 22:51:25 by csantos-          #+#    #+#             */
/*   Updated: 2021/07/25 15:28:37 by csantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include <unistd.h>

int	g_mess_received;

/**
* SERVER
**/

void	printt_id(pid_t id);
int		setup_handlers(void);
void	sig_action(int signum, siginfo_t *info, void *ucontext);
void	receive_message(int num_bit, pid_t id_client);

/**
* CLIENT
**/

pid_t	get_numid(char *arg);
int		send_message(char *arg, pid_t num_id);
void	check_message(int signum);

#endif
