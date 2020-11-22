/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:09:59 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/22 17:10:11 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_specifier.h"

void	null_format(t_format *f)
{
	f->fl = 0;
	f->pr = 0;
	f->w = NULL;
	f->wp = 0;
	f->wf = 0;
	f->sp = 0;
	f->re = NULL;
	f->pl = -1;
	f->t = NULL;
	f->su = 1;
	f->isspase = 0;
}

void	print_format(t_format *f)
{
	printf("\n----------------------------\nflags |%c|\n", f->fl);
	printf("precision |%c|\n", f->pr);
	printf("width |%s|\n", f->w);
	printf("wid_pre |%li|\n", f->wp);
	printf("wid_fls |%li|\n", f->wf);
	printf("specifier |%c|\n", f->sp);
	printf("result |%s|\n", f->re);
	printf("plen |%li| =? %li\n", f->pl, ft_strlen(f->t));
	printf("help |%s|\n", f->t);
	printf("success |%i|\n\n", f->su);
}

void	*format_specifier(char **str, va_list *app, int *len)
{
	t_format	f;

	(*str)++;
	null_format(&f);
	while (**str == 32 && **str != '\0')
	{
		f.isspase = 1;
		(*str)++;
	}
	while (ft_findchr("-01234567890*", **str) > 0)
	{
		if (ft_findchr("-0", **str) > 0 && f.su)
			f.su = f_flags(str, &f);
		if (ft_findchr("1234567890*", **str) > 0 && f.su)
			f.su = f_width(str, app, &f, 'f');
	}
	if (ft_findchr(".", **str) > 0 && f.su)
		f.su = f_precision(str, &f);
	if (ft_findchr("1234567890*", **str) > 0 &&
			(f.su || f.su == -1))
		f.su = f_width(str, app, &f, 'p');
	if (ft_findchr("cspdiuxXo%", **str) > 0 && f.su)
		f.su = f_specifier(str, app, &f);
	return (result_char(len, &f));
}
