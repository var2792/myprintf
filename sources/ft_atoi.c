/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:20:58 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/17 13:35:05 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libtemp.h"

static int	ft_check_isspace(char s)
{
	if (s == '\t' || s == 32 || s == '\n'
		|| s == '\v' || s == '\f' || s == '\r')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int			i;
	long int	num;
	int			m;

	i = 0;
	num = 0;
	m = 1;
	while (ft_check_isspace(str[i]) && str[i] != '\0')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			m = -1;
		i++;
	}
	while ((str[i] > 47 && str[i] < 58) && str[i])
	{
		if (num < -2147483648)
			return (-1);
		if (num > 2147483647)
			return (0);
		num = num * 10 + m * (str[i] - 48);
		i++;
	}
	return (num);
}
