/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:38:02 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/01 19:41:03 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_add_minus_long(t_print *arg, char *str, long data)
{
	if (arg->width > ft_long_nbrlen(data) && arg->prec > ft_long_nbrlen(data)
		&& arg->prec && arg->width && data < 0)
	{
		str[ft_strlen(str) - arg->prec - 1] = '-';
		return (1);
	}
	else if (!arg->minus && arg->width > ft_long_nbrlen(data)
		&& arg->prec && arg->width && data < 0 && arg->width > arg->prec)
	{
		str[ft_strlen(str) - ft_long_nbrlen(data)] = '-';
		return (1);
	}
	else if (data < 0 && (arg->dot || arg->zero))
	{
		str[0] = '-';
		return (1);
	}
	else if (data < 0 && arg->zero && arg->width > arg->prec)
	{
		str[arg->width - arg->prec - 1] = '-';
		return (1);
	}
	else
		return (0);
}




void	ft_handle_minus_long(t_print *arg, char *text, long data, char *str)
{
	int	flag;
	int	num_len;
	int	dot_len;
	int	text_len;
	int	str_len;

	flag = ft_add_minus_long(arg, str, data);
	num_len = ft_long_nbrlen(data);
	dot_len = num_len - 1;
	text_len = ft_strlen(text);
	str_len = ft_strlen(str);
	ft_prec_aux(str, flag, arg);
	if (arg->width >= num_len && arg->prec < num_len)
		ft_memcpy(str, text, text_len);
	else if (arg->width >= num_len && arg->prec > dot_len && !flag)
		ft_memcpy(&str[arg->prec - text_len], text, text_len);
	else if (arg->width >= num_len && arg->prec > dot_len && flag)
		ft_memcpy(&str[arg->prec - text_len + 2], &text[1], text_len - 1);
	else if (arg->prec >= num_len && flag)
		ft_memcpy(&str[str_len - text_len + 1], &text[1], text_len);
	else if (arg->prec >= num_len)
		ft_memcpy(&str[str_len - text_len], text, text_len);
	str[str_len] = '\0';
}

void	ft_handle_width_long(t_print *arg, char *text, long data, char *str)
{
	int	flag;
	int	num_len;
	int	text_len;
	int	str_len;

	flag = ft_add_minus_long(arg, str, data);
	num_len = ft_long_nbrlen(data);
	text_len = ft_strlen(text);
	str_len = ft_strlen(str);
	if (arg->minus && arg->prec > ft_long_nbrlen(data) - 1 && flag)
		ft_memset(&str[1], '0', arg->prec);
	else if (arg->minus && arg->prec > ft_long_nbrlen(data) - 1 && !flag)
		ft_memset(str, '0', arg->prec);
	else if (arg->width >= num_len && arg->minus)
		ft_memcpy(str, text, text_len);
	else if (arg->width >= num_len && !flag)
		ft_memcpy(&str[str_len - text_len], text, text_len);
	else if (arg->width >= num_len && flag)
		ft_memcpy(&str[str_len - text_len + 1], &text[1], text_len - 1);
}

void	ft_handle_prec_long(t_print *arg, char *text, long data, char *str)
{
	int	flag;
	int	text_len;
	int	str_len;

	flag = ft_add_minus_long(arg, str, data);
	text_len = ft_strlen(text);
	str_len = ft_strlen(str);
	if (arg->prec >= text_len && !flag)
		ft_memcpy(&str[str_len - text_len], text, text_len);
	else if (arg->prec >= text_len && flag)
		ft_memcpy(&str[str_len - text_len + 1], &text[1], text_len);
	str[str_len] = '\0';
}

void	ft_add_zeroes_long(t_print *arg, char *ret, long data)
{
	if (arg->zero && arg->width > ft_long_nbrlen(data) && data > 0 && arg->minus)
		ft_memset(ret, '0', arg->width - ft_long_nbrlen(data));
	else if (arg->zero && arg->width > ft_long_nbrlen(data) && arg->minus)
		ft_memset(&ret[1], '0', arg->width - ft_long_nbrlen(data));
	else if (arg->zero && arg->width > ft_long_nbrlen(data) && data < 0)
		ft_memset(&ret[1], '0', arg->width - ft_long_nbrlen(data));
	else if (arg->zero && arg->width > ft_long_nbrlen(data))
		ft_memset(ret, '0', arg->width - ft_long_nbrlen(data));
}
