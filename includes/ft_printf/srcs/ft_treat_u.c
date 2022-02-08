/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:40:19 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/01 19:40:20 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_add_data_u(t_print *arg, char *str, unsigned int data)
{
	char	*text;

	if (arg->dot && !arg->prec && data == 0)
		return ;
	text = ft_utoa(data);
	if (arg->minus)
		ft_handle_minus_u(arg, text, data, str);
	else if (arg->width > arg->prec)
		ft_handle_width_u(arg, text, data, str);
	else if (arg->dot)
		ft_handle_prec_u(arg, text, str);
	free(text);
}

int	ft_treat_u(va_list args, t_print *arg)
{
	unsigned int	data;
	char			*ret;
	int				count;

	data = (unsigned int)va_arg(args, unsigned int);
	if (arg->flags)
	{	
		if (!arg->width && arg->dot && !arg->prec && data == 0)
			return (0);
		ret = ft_create_str_u(arg, data);
		if (!ret)
			return (ft_no_flag_u(data));
		ft_if_add_zero_u(arg, ret, data);
		ft_add_data_u(arg, ret, data);
		if (!arg->dot)
			ft_add_zeroes_u(arg, ret, data);
		ft_putstr_fd(ret, 1);
		count = ft_strlen(ret);
		free(ret);
	}
	else
	{
		ft_putnbr_u_fd(data, 1);
		return (ft_unbrlen(data));
	}
	return (count);
}

//int	ft_treat_u(va_list args, t_print *arg)
//{
//	unsigned int	data;
//	char			*ret;
//	char			*data2;
//	int				ret2;
//	int				len;
//
//	data = (unsigned int)va_arg(args, unsigned int);
//	len = 0;
//	if (arg->flags)
//	{
//		if (arg->minus && arg->width > ft_unbrlen(data))
//		{
//			ret = ft_calloc(sizeof(char), (arg->width + 3));
//			ft_memset(ret, ' ', arg->width);
//			data2 = ft_utoa(data);
//			ft_strlcpy(ret, data2, ft_strlen(data2) + 1);
//			ret[ft_strlen(data2)] = ' ';
//			ret[arg->width] = '\0';
//			free(data2);
//			ft_putstr_fd(ret, 1);
//			free(ret);
//			return (arg->width);
//		}
//		else if (arg->zero && arg->width > ft_unbrlen(data))
//		{
//			ret = ft_calloc(sizeof(char), (arg->width + 1));
//			ft_memset(ret, 48, arg->width);
//			data2 = ft_utoa(data);
//			len = ft_strlen(data2);
//			ft_strlcpy(&ret[arg->width - len], data2, len + 1);
//			ret[arg->width] = '\0';
//			free(data2);
//			ft_putstr_fd(ret, 1);
//			free(ret);
//			return (arg->width);
//		}
//		else if (arg->dot && arg->prec >= ft_unbrlen(data))
//		{
//			ret = ft_calloc(arg->prec + 1, sizeof(char));
//			ft_memset(ret, 48, arg->prec);
//			data2 = ft_utoa(data);
//			len = ft_strlen(data2);
//			ft_strlcpy(&ret[arg->prec - len], data2, len + 1);
//			ret[arg->prec] = '\0';
//			free(data2);
//			ft_putstr_fd(ret, 1);
//			free(ret);
//			return (arg->prec);
//		}
//		else if (arg->dot && !arg->width && data == 0)
//			return (0);
//		else if ((arg->hash || arg->space) && arg->width > ft_unbrlen(data))
//		{
//			ret = ft_calloc(sizeof(char), (arg->width + 1));
//			ft_memset(ret, ' ', arg->width);
//			data2 = ft_utoa(data);
//			len = ft_strlen(data2);
//			ft_strlcpy(&ret[arg->width - len], data2, len + 1);
//			ret[len] = ' ';
//			ret[arg->width] = '\0';
//			free(data2);
//			ft_putstr_fd(ret, 1);
//			free(ret);
//			return (arg->width);
//		}
//		else if (arg->space)
//		{
//			ft_putchar_fd(' ', 1);
//			data2 = ft_utoa(data);
//			ft_putstr_fd(data2, 1);
//			free(data2);
//			return (ft_unbrlen(data) + 1);
//		}
//		else if (arg->width > ft_unbrlen(data))
//		{
//			ret = ft_calloc(sizeof(char), (arg->width + 1));
//			ft_memset(ret, ' ', arg->width);
//			data2 = ft_utoa(data);
//			len = ft_strlen(data2);
//			ft_strlcpy(&ret[arg->width - len], data2, len + 1);
//			ret[arg->width] = '\0';
//			free(data2);
//			ft_putstr_fd(ret, 1);
//			free(ret);
//			return (arg->width);
//		}
//		else
//		{
//			ft_putnbr_u_fd(data, 1);
//			ret = ft_utoa(data);
//			ret2 = ft_strlen(ret);
//			free(ret);
//		}
//	}
//	else
//	{
//		ft_putnbr_u_fd(data, 1);
//		ret = ft_utoa(data);
//		ret2 = ft_strlen(ret);
//		free(ret);
//	}
//	return (ret2);
//}
