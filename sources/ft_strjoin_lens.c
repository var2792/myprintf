/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_lens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:05:53 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/22 17:06:03 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libtemp.h"

void	*ft_strjoin_lens(void *s1, void *s2, int len1, int len2)
{
	int				i;
	int				j;
	unsigned char	*res;
	unsigned char	*u1;
	unsigned char	*u2;

	u1 = (unsigned char*)s1;
	u2 = (unsigned char*)s2;
	if (!u1 && !u2)
		return (((unsigned char*)NULL));
	if (!(res = malloc(sizeof(char) * (len1 + len2 + 1))))
		return (((unsigned char*)NULL));
	i = 0;
	j = 0;
	if (!(u1 == NULL))
	{
		while (i < len1)
			res[i++] = u1[j++];
		free(u1);
	}
	j = 0;
	while (j < len2)
		res[i++] = u2[j++];
	res[i] = '\0';
	return (res);
}
