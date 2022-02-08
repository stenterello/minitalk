/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 19:40:09 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/01 19:40:10 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_ptrnbrlen(size_t n, size_t b_len)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		n = n / b_len;
		i++;
	}
	return (i + 2);
}

char	*ft_utoa_base(size_t n, char *base, int b_len)
{
	char	*ret;
	int		len;

	len = ft_ptrnbrlen(n, b_len);
	ret = ft_calloc(len + 1, sizeof(char));
	if (!ret)
		return (0);
	ret[len--] = '\0';
	while (len >= 0)
	{
		ret[len] = base[n % b_len];
		n = n / b_len;
		len--;
	}
	ret[1] = 'x';
	return (ret);
}

char	*ft_get_ptr_str(size_t data, char *base)
{
	char	*convert;
	char	*str;

	convert = ft_calloc(ft_ptrnbrlen(data, 16) + 1, sizeof(char));
	str = ft_utoa_base(data, base, 16);
	ft_memcpy(convert, str, ft_ptrnbrlen(data, 16));
	convert[ft_ptrnbrlen(data, 16)] = '\0';
	free(str);
	return (convert);
}

char	*ft_create_str_ptr(t_print *arg, char *convert)
{
	char	*ret;

	if (arg->width > (int)ft_strlen(convert) && arg->width > arg->prec)
	{
		ret = ft_calloc(arg->width + 3, sizeof(char));
		ft_memset(ret, ' ', arg->width);
	}
	else
	{
		ret = ft_calloc(ft_strlen(convert) + 1, sizeof(char));
		ft_strlcpy(ret, convert, ft_strlen(convert) + 1);
	}
	return (ret);
}

void	ft_add_data_ptr(t_print *arg, char *ret, char *convert)
{
	if (arg->minus && arg->width > (int)ft_strlen(convert))
		ft_memcpy(ret, convert, ft_strlen(convert));
	else if (arg->width > (int)ft_strlen(convert))
		ft_memcpy(&ret[arg->width - ft_strlen(convert)], convert, ft_strlen(convert));
}

int	ft_treat_ptr(va_list args, t_print *arg)
{
	size_t			data;
	int				count;
	char			*convert;
	char			*base;
	char			*ret;

	base = "0123456789abcdef";
	data = va_arg(args, size_t);
	count = 0;
	convert = ft_get_ptr_str(data, base);
	if (arg->dot && !arg->prec && data == 0)
		return (0);
	ret = ft_create_str_ptr(arg, convert);
	ft_add_data_ptr(arg, ret, convert);
	free(convert);
	ft_putstr_fd(ret, 1);
	count = ft_strlen(ret);
	free(ret);
	return (count);
}
