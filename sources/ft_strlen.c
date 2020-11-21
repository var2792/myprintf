/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:21:16 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/17 21:56:16 by tarneld          ###   ########.fr       */
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
