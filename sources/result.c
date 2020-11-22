/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:11:52 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/22 17:11:57 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_specifier.h"

void	not_null(t_format *f, int fl, int *len)
{
	unsigned char *sp;

	if (f->t != NULL)
	{
		if ((fl == 0 && f->re == NULL) || (!f->pr && !f->fl && !f->wf))
			f->re = f->t;
		*len += f->pl;
	}
	if (!f->re && fl == 0)
		f->re = f->t;
	if (f->isspase)
	{
		sp = malloc(2 * sizeof(char));
		sp[0] = 32;
		sp[1] = 0;
		sp = ft_strjoin_lens(sp, f->re, 1, f->pl);
		free(f->re);
		f->re = sp;
		*len += 1;
	}
}

void	if_null(t_format *f)
{
	if (f->t == NULL || (f->t[0] == '0' && f->wp == 0))
	{
		if (f->pr == '.' && f->wp <= 0)
		{
			f->t = ft_strjoin_lens(f->t, " ", 0, 0);
			f->pl = 0;
		}
	}
}

void	*result_char(int *len, t_format *f)
{
	int fl;

	fl = 0;
	if (f->su == 1)
	{
		if_null(f);
		if (f->fl == '0' || f->pr == '.')
			fl = out_zero(f);
		if (f->fl == '-')
			fl = out_minus(f);
		if ((!f->fl && f->wf != 0) || fl == -1)
			fl = out_without(f);
		not_null(f, fl, len);
		return (f->re);
	}
	*len = -1;
	return (NULL);
}
