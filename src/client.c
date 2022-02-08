#include "../includes/minitalk.h"

void	ft_send_string(pid_t serv_pid, char *str, int len)
{
	int	sig;

	while (len--)
	{
		decrypt.bits = 0b10000000;
		while (decrypt.bits)
		{
			if (*str & decrypt.bits)
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
	decrypt.bits >>= 1;
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
