#include "../ft_printf.h"

int	ft_long_nbrlen(long n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_ltoa(long n)
{
	char	*str;
	int		i;
	long	nbr;

	nbr = n;
	str = malloc(sizeof(char) * (ft_long_nbrlen(nbr) + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		str[i++] = '-';
		nbr *= -1;
	}
	ft_putnbr(nbr, str, &i);
	str[i] = '\0';
	return (str);
}

void	ft_add_data_long(t_print *arg, char *str, long data)
{
	char	*text;

	if (arg->dot && !arg->prec && data == 0)
		return ;
	text = ft_ltoa(data);
	if (arg->minus && arg->width > arg->prec)
		ft_handle_minus_long(arg, text, data, str);
	else if (arg->width > arg->prec)
		ft_handle_width_long(arg, text, data, str);
	else if (arg->dot)
		ft_handle_prec_long(arg, text, data, str);
	else if ((arg->space || arg->plus) && data >= 0)
		ft_strlcpy(&str[1], text, ft_strlen(text) + 1);
	else
		ft_strlcpy(str, text, ft_strlen(text) + 1);
	str[ft_strlen(str)] = '\0';
	free(text);
}

char	*ft_create_str_long(t_print *arg, long data2)
{
	char	*ret;

	if (arg->width > arg->prec && arg->width >= ft_long_nbrlen(data2))
	{
		ret = ft_calloc(arg->width, sizeof(char));
		ft_memset(ret, ' ', arg->width);
	}
	else if (arg->prec >= arg->width
		&& arg->prec >= ft_long_nbrlen(data2) && data2 < 0)
	{
		ret = ft_calloc(arg->prec + 1, sizeof(char));
		ft_memset(ret, '0', arg->prec + 1);
	}
	else if (arg->prec >= arg->width && arg->prec >= ft_long_nbrlen(data2))
	{
		ret = ft_calloc(arg->prec, sizeof(char));
		ft_memset(ret, '0', arg->prec);
	}
	else if ((arg->space || arg->plus) && data2 >= 0)
	{
		ret = ft_calloc(ft_long_nbrlen(data2) + 1, sizeof(char));
		ft_memset(ret, ' ', ft_long_nbrlen(data2) + 1);
	}
	else
		return (NULL);
	return (ret);
}

void	ft_putlong_fd(long n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			n *= -1;
			ft_putchar_fd('-', fd);
		}
		if (n > 9)
		{
			ft_putlong_fd(n / 10, fd);
			ft_putlong_fd(n % 10, fd);
		}
		else
			ft_putchar_fd(n + 48, fd);
	}
}

int	ft_no_flag_long(long data)
{
	ft_putlong_fd(data, 1);
	return (ft_long_nbrlen(data));
}

int	ft_treat_long(int data, t_print *arg)
{
	long	data2;
	char	*ret;
	int		count;

	data2 = (long)data;
	ret = ft_create_str_long(arg, data2);
	if (!ret)
		return (ft_no_flag_long(data2));
	ft_add_data_long(arg, ret, data);
	if (!arg->dot)
		ft_add_zeroes_long(arg, ret, data);
	ft_putstr_fd(ret, 1);
	count = ft_strlen(ret);
	free(ret);
	return (count);
}
