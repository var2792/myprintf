/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_out_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:37:32 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/23 18:37:34 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_specifier.h"

int		out_point_zero(t_format *f)
{
	long int		sz;
	int				i;
	unsigned char	*t;

	i = -1;
	t = NULL;
	sz = f->wp + 2;
	if (f->wp == 0)
	{
		f->re = (unsigned char*)ft_strjoin_lens(f->re, f->t, 0, 2);
		f->pl = 2;
		free(f->t);
		return (1);
	}
	while (++i + f->pl < sz)
		t = ft_strjoin_lens(t, "0", ft_strlen(t), 1);
	t = (unsigned char*)ft_strjoin_lens(t, &(f->t[2]), ft_strlen(t), ft_strlen(f->t) - 2);
	f->re = (unsigned char*)ft_strjoin_lens(f->t, t, 2, ft_strlen(t));
	f->pl += i;
	free(t);
	return (1);
}

int		out_other_zero(t_format *f)
{
	unsigned int	i;
	unsigned char	*temp;

	i = 0;
	if (f->sp == 'p' && f->pr != 0)
		return (out_point_zero(f));
	if (f->wp < 0 || ft_strlen(f->t) == 0)
		return (0);
	temp = f->t + i;
	while (i < f->wp && temp[0] != 0)
	{
		f->re = ft_strjoin_lens(f->re, temp, ft_strlen(f->re), 1);
		temp = f->t + ++i;
	}
	if (!f->re && f->wp == 0 && f->fl == '0')
	{
		f->re = ft_strjoin_lens(f->re, temp, ft_strlen(f->re), f->pl);
		i = f->pl;
	}
	if (f->wp == 0)
		f->re = ft_strjoin_lens(f->re, temp, ft_strlen(f->re), 0);
	f->pl = i;
	free(f->t);
	return (1);
}

int		negat_zero_num(t_format *f, unsigned char *temp, int i)
{
	unsigned char	*t;

	t = NULL;
	if (f->pr == '.' && f->wp >= 0)
	{
		temp = ft_strjoin_lens(temp, "0", ft_strlen(temp), 1);
		i++;
	}
	t = ft_strjoin_lens(t, "-", 0, 1);
	t = ft_strjoin_lens(t, temp, 1, i);
	free(temp);
	f->re = (unsigned char*)ft_strjoin_lens(t, &(f->t[1]),
		ft_strlen(t), f->pl - 1);
	f->pl += i;
	free(f->t);
	return (1);
}
