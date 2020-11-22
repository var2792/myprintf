/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:10:43 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/22 17:11:34 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_specifier.h"

int		out_str_zero(t_format *f)
{
	unsigned int	i;
	unsigned char	*temp;

	i = 0;
	if (f->wp < 0 || ft_strlen(f->t) == 0)
		return (0);
	temp = f->t + i;
	while (i < f->wp && temp[0] != 0)
	{
		f->re = ft_strjoin_lens(f->re, temp, ft_strlen(f->re), 1);
		temp = f->t + ++i;
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

int		out_zero(t_format *f)
{
	long int		sz;
	int				i;
	unsigned char	*t;

	i = -1;
	t = NULL;
	sz = (f->fl == '0' && (f->pr != '.' || f->wp < 0)) ? f->wf : f->wp;
	if (f->fl == '0' && f->pr == '.' && f->pl < f->wf && f->wp >= 0)
		f->fl = 0;
	if (f->sp == 's')
		return (out_str_zero(f));
	if (f->sp == 'c')
		return (-1);
	if (sz < 0 || f->pl >= sz || ft_strlen(f->t) == 0)
		if (!(f->pl == sz && (f->sp == 'i' || f->sp == 'd') && f->t[0] == '-'))
			return (0);
	while (++i + f->pl < sz)
		t = ft_strjoin_lens(t, "0", ft_strlen(t), 1);
	if ((f->sp == 'i' || f->sp == 'd') && f->t[0] == '-')
		return (negat_zero_num(f, t, i));
	else
		f->re = (unsigned char*)ft_strjoin_lens(t, f->t, ft_strlen(t), f->pl);
	f->pl += i;
	free(f->t);
	return (1);
}

int		out_minus(t_format *f)
{
	long int		size;
	int				i;
	unsigned char	*t;

	i = 0;
	t = NULL;
	size = f->wf;
	if (size < 0 || f->pl >= size)
		return (0);
	while (i + f->pl < size)
	{
		t = ft_strjoin_lens(t, " ", ft_strlen(t), 1);
		i++;
	}
	if (f->pr == '.' && f->re != NULL)
		f->re = (unsigned char*)ft_strjoin_lens(f->re, t, ft_strlen(f->re), i);
	else
		f->re = (f->t[0] == 0 &&
			f->pl == 1) ? (unsigned char*)ft_strjoin_lens(f->t, t,
			1, i) : (unsigned char*)ft_strjoin_lens(f->t,
			t, ft_strlen(f->t), i);
	free(t);
	f->pl += i;
	return (1);
}

int		out_without(t_format *f)
{
	long int		size;
	int				i;
	unsigned char	*temp;

	i = -1;
	temp = NULL;
	size = f->wf;
	if (f->pl > size)
		return (0);
	while (++i + f->pl < size)
		temp = ft_strjoin_lens(temp, " ", ft_strlen(temp), 1);
	if (f->pr == '.' && f->re != NULL)
	{
		temp = (unsigned char*)ft_strjoin_lens(temp, f->re, i, f->pl);
		free(f->re);
		f->re = temp;
	}
	else
	{
		f->re = (unsigned char*)ft_strjoin_lens(temp, f->t, i, f->pl);
		free(f->t);
	}
	f->pl += i;
	return (1);
}
