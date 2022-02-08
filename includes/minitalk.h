#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <sys/types.h>
# include "libft/libft.h"

void	die(char *str);
void	usage(void);

typedef struct s_signal
{
	unsigned int	bits;
	char			symbol;
	int				pid;
}	t_signal;

t_signal	decrypt;

#endif
