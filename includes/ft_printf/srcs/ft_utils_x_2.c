#include "../ft_printf.h"

void	ft_set_string(char *ret, char *text, char c, int size)
{
	ft_memset(ret, c, size - ft_strlen(text));
	ft_memcpy(&ret[size - ft_strlen(text)], text, ft_strlen(text));
}

void	ft_set_string2(char *ret, char *text, t_print *arg)
{
	ft_memset(ret, '0', arg->prec - ft_strlen(text));
	ft_memcpy(&ret[arg->prec - ft_strlen(text)], text, ft_strlen(text));
	ft_memset(&ret[arg->prec], ' ', arg->width - arg->prec);
}

void	ft_set_string3(char *ret, char *text, char c, int size)
{
	ft_memcpy(ret, text, ft_strlen(text));
	ft_memset(&ret[ft_strlen(text)], c, size - ft_strlen(text));
}
