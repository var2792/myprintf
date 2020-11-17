/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:21:10 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/17 13:42:06 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libtemp.h"

char	*ft_strjoin_one(void *s1, int s2, int len)
{
	int		i;
	int		j;
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
	return ((char*)res);
}

char	*ft_strjoin_free(char *s1, char const *s2, int len)
{
	int		i;
	int		j;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	if (!(res = malloc(sizeof(char) * (ft_strlen(s1) + len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	if (!(s1 == NULL))
	{
		while (s1[i])
			res[i++] = s1[j++];
		free(s1);
	}
	j = 0;
	while (s2[j] && j < len)
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}
