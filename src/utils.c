#include "../includes/minitalk.h"

void	die(char *str)
{
	ft_putstr_fd(str, 1);
	exit(-1);
}

void	usage(void)
{
	ft_putstr_fd("Not enough arguments to run ./client executable\n", 1);
	die("Usage: ./client [PID] [MESSAGE]\n");
}
