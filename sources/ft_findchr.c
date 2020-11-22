/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:07:48 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/22 17:07:55 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libtemp.h"

int		ft_findchr(const char *st, char c)
{
	int		i;

	i = 0;
	if (!st)
		return (-1);
	while (c != st[i])
	{
		if (st[i] == '\0')
			break ;
		i++;
	}
	if (st[i] == '\0' && c != '\0')
		return (-1);
	return (1);
}
