/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddelladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 16:53:35 by ddelladi          #+#    #+#             */
/*   Updated: 2022/02/08 16:55:59 by ddelladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
