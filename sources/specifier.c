/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:13:30 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/22 17:13:39 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_specifier.h"

int		char_specifier(char **str, va_list *app, t_format *f)
{
	unsigned char	up;

	up = (unsigned char)va_arg(*app, int);
	f->t = (unsigned char*)ft_strjoin_lens(f->t, &up, ft_strlen(f->t), 1);
	f->pl = 1;
	(*str)++;
	if (f->wf < 0)
	{
		f->fl = '-';
		f->wf *= -1;
	}
	return (1);
}

int		string_specifier(char **str, va_list *app, t_format *f)
{
	unsigned char	*t;
	unsigned char	*p;

	t = NULL;
	p = va_arg(*app, unsigned char*);
	if (p == NULL)
	{
		p = ft_strjoin_lens(p, "(null)", 0, 6);
		t = (unsigned char*)ft_strjoin_lens(t, p, ft_strlen(t), ft_strlen(p));
		free(p);
	}
	else
		t = (unsigned char*)ft_strjoin_lens(t, p, ft_strlen(t), ft_strlen(p));
	f->t = (unsigned char*)ft_strjoin_lens(f->t, t,
		ft_strlen(f->t), ft_strlen(t));
	free(t);
	f->pl = ft_strlen(f->t);
	(*str)++;
	if (f->wf < 0)
	{
		f->fl = '-';
		f->wf *= -1;
	}
	return (1);
}

int		pointer_specifier(char **str, va_list *app, t_format *f)
{
	unsigned char	*t;
	unsigned char	*p;
	long int		num_p;

	t = NULL;
	num_p = va_arg(*app, long int);
	p = malloc(sizeof(char) * 3);
	p[0] = '0';
	p[1] = 'x';
	p[2] = '\0';
	t = (unsigned char*)ft_itoa_base(num_p, 'x');
	p = (unsigned char*)ft_strjoin_lens(p, t, ft_strlen(p), ft_strlen(t));
	f->t = (unsigned char*)ft_strjoin_lens(f->t, p,
		ft_strlen(f->t), ft_strlen(p));
	free(t);
	free(p);
	f->pl = ft_strlen(f->t);
	(*str)++;
	return (1);
}

int		percent_specifier(char **str, t_format *f)
{
	unsigned char	*temp;

	temp = NULL;
	f->t = (unsigned char*)ft_strjoin_lens(f->t,
		"%", ft_strlen(f->t), 1);
	free(temp);
	f->pl = ft_strlen(f->t);
	(*str)++;
	return (1);
}

int		f_specifier(char **str, va_list *app, t_format *f)
{
	f->sp = **str;
	if (f->pl == -1)
		f->pl = 0;
	if (f->sp == 'c')
		return (char_specifier(str, app, f));
	if (f->sp == 's')
		return (string_specifier(str, app, f));
	if (f->sp == 'p')
		return (pointer_specifier(str, app, f));
	if (f->sp == '%')
		return (percent_specifier(str, f));
	if (f->sp == 'd' || f->sp == 'i')
		return (integer_specifier(str, app, f));
	if (f->sp == 'u')
		return (unsigint_specifier(str, app, f));
	if (f->sp == 'X')
		return (unsighex_big_specifier(str, app, f));
	if (f->sp == 'x')
		return (unsighex_lit_specifier(str, app, f));
	if (f->sp == 'o')
		return (unsigoct_specifier(str, app, f));
	return (0);
}
