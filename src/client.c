/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:53:29 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/08 16:55:54 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_signal	g_decrypt;

void	ft_send_string(pid_t serv_pid, char *str, int len)
{
	int	sig;

	while (len--)
	{
		g_decrypt.bits = 0b10000000;
		while (g_decrypt.bits)
		{
			if (*str & g_decrypt.bits)
				sig = kill(serv_pid, SIGUSR1);
			else
				sig = kill(serv_pid, SIGUSR2);
			if (sig == -1)
				die("Bad pid\n");
			pause();
			usleep(100);
		}
		str++;
	}
}

void	ack(int num)
{
	(void) num;
	ft_putstr_fd("Message received.\n", 1);
	exit(0);
}

void	move_bits(int num)
{
	(void) num;
	g_decrypt.bits >>= 1;
}

int	main(int argc, char **argv)
{
	pid_t				serv_pid;
	char				*str;
	int					len;
	struct sigaction	act;
	struct sigaction	act2;	

	if (argc != 3)
		usage();
	else
	{
		act.sa_handler = &move_bits;
		sigemptyset(&act.sa_mask);
		act.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR1, &act, NULL);
		act2.sa_handler = &ack;
		sigemptyset(&act2.sa_mask);
		act2.sa_flags = SA_SIGINFO;
		sigaction(SIGUSR2, &act2, NULL);
		str = argv[2];
		len = ft_strlen(str) + 1;
		serv_pid = ft_atoi(argv[1]);
		ft_send_string(serv_pid, str, len);
	}
	return (0);
}
