/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:53:44 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/08 16:55:49 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_signal	g_decrypt;

void	ft_print_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_print_str(int num, siginfo_t *info, void *context)
{
	(void)context;
	if (num == SIGUSR1)
		g_decrypt.symbol |= g_decrypt.bits;
	g_decrypt.bits >>= 1;
	if (!g_decrypt.bits)
	{
		if (!g_decrypt.symbol)
		{
			ft_putchar_fd('\n', 1);
			usleep(500);
			kill(info->si_pid, SIGUSR2);
		}
		else
			ft_putchar_fd(g_decrypt.symbol, 1);
		g_decrypt.bits = 0b10000000;
		g_decrypt.symbol = 0;
	}
	usleep(100);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;
	int					res1;
	int					res2;

	g_decrypt.bits = 0b10000000;
	g_decrypt.symbol = 0;
	act.sa_sigaction = &ft_print_str;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	res1 = sigaction(SIGUSR1, &act, NULL);
	res2 = sigaction(SIGUSR2, &act, NULL);
	if (res1 != 0 || res2 != 0)
		die("Signal error\n");
	ft_print_pid();
	while (1)
		pause();
	return (0);
}
