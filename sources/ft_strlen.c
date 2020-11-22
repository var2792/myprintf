/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:04:54 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/22 17:05:03 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libtemp.h"

size_t		ft_strlen(void *str)
{
	unsigned long i;

	i = 0;
	if ((unsigned char *)str == NULL)
		return (0);
	while (((unsigned char *)str)[i] != '\0')
		i++;
	return (i);
}
