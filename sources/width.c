/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:09:13 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/22 17:09:21 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_specifier.h"

static int	width_star(char **str, va_list *app, t_format *f, char flag)
{
	int len;

	len = va_arg(*app, unsigned int);
	if (flag == 'p')
		f->wp = len;
	else if (flag == 'f')
		f->wf = len;
	else
		return (0);
	(*str)++;
	return (1);
}

int			f_width(char **str, va_list *app, t_format *f, char flag)
{
	int i;

	i = 0;
	if (f->pl == -1)
		f->pl = 0;
	if (**str == '*')
		return (width_star(str, app, f, flag));
	while (**str > 47 && **str < 58)
	{
		f->w = (char*)ft_strjoin_lens(f->w, *str, i, 1);
		i++;
		(*str)++;
	}
	if (f->w != NULL)
	{
		if (flag == 'p')
			f->wp = ft_atoi(f->w);
		if (flag == 'f')
			f->wf = ft_atoi(f->w);
		free(f->w);
		f->w = NULL;
		return (1);
	}
	return (0);
}
