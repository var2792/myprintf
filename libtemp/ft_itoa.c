/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 12:45:35 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/17 02:35:51 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtemp.h"

static char	*res10(int i, int fl, int *convert)
{
	char	*res;
	int		n;

	if (!(res = (char *)malloc((i + fl + 1) * sizeof(char))))
		return (NULL);
	i = i + fl - 1;
	n = fl;
	while (i >= fl)
	{
		res[n] = convert[i - fl] + 48;
		n++;
		i--;
	}
	if (fl)
		res[0] = '-';
	res[n] = '\0';
	return (res);
}

static char	*res16(int i, int *convert)
{
	char	*base16;
	char	*res;
	int		n;

	base16 = "0123456789ABCDEF";
	if (!(res = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	i--;
	n = 0;
	while (i >= 0)
	{
		res[n] = base16[convert[i]];
		n++;
		i--;
	}
	res[n] = '\0';
	return (res);
}

static char	*res16l(int i, int *convert)
{
	char	*base16l;
	char	*res;
	int		n;

	base16l = "0123456789abcdef";
	if (!(res = (char *)malloc((i + 1) * sizeof(char))))
		return (NULL);
	i--;
	n = 0;
	while (i >= 0)
	{
		res[n] = base16l[convert[i]];
		n++;
		i--;
	}
	res[n] = '\0';
	return (res);
}

char		*ft_itoa_base(long int value, char base)
{
	long long int	val;
	int			i;
	int			convert[512];
	int			b;
	int			fl;

	val = value;
	fl = 0;
	if (val < 0)
	{
		val *= -1;
		if (base == 'A')
			fl = 1;
	}
	i = 0;
	b = (base == 'A') ? 10 : 16;
	while (val > b - 1)
	{
		convert[i++] = val % b;
		val = val / b;
	}
	convert[i++] = val;
	if (base == 'A')
		return (res10(i, fl, convert));
	if (base == 'X')
		return (res16(i, convert));
	if (base == 'x')
		return (res16l(i, convert));
	return(NULL);
}
