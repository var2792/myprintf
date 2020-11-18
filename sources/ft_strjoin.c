/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:21:10 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/18 12:48:06 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libtemp.h"

void	*ft_strjoin_one(void *s1, int s2, int len)
{
	int				i;
	int				j;
	unsigned char	*res;

	if (!(res = malloc(sizeof(char) * (ft_strlen((char*)s1) + len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	if (!(s1 == NULL))
	{
		while (((unsigned char*)s1)[i])
			res[i++] = ((unsigned char*)s1)[j++];
		free(s1);
	}
	res[i++] = (unsigned char)s2;
	res[i] = '\0';
	return (res);
}

void	*ft_strjoin_free(void *s1, void *s2, int len)
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
	if (!(res = malloc(sizeof(char) * (ft_strlen(u1) + len + 1))))
		return (((unsigned char*)NULL));
	i = 0;
	j = 0;
	if (!(u1 == NULL))
	{
		while (u1[i])
			res[i++] = u1[j++];
		free(u1);
	}
	j = 0;
	while (u2[j] && j < len)
		res[i++] = u2[j++];
	res[i] = '\0';
	return (res);
}

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
