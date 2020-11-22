/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:13:07 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/22 17:13:16 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_specifier.h"

int		integer_specifier(char **str, va_list *app, t_format *f)
{
	unsigned char	*temp;

	temp = NULL;
	temp = (unsigned char*)ft_itoa_base(va_arg(*app, int), 'A');
	f->t = (unsigned char*)ft_strjoin_lens(f->t, temp,
		ft_strlen(f->t), ft_strlen(temp));
	free(temp);
	f->pl = ft_strlen(f->t);
	(*str)++;
	if (f->wf < 0)
	{
		f->fl = '-';
		f->wf *= -1;
	}
	return (1);
}

int		unsigint_specifier(char **str, va_list *app, t_format *f)
{
	unsigned char	*temp;

	temp = NULL;
	temp = (unsigned char*)ft_itoa_base(va_arg(*app, unsigned int), 'A');
	f->t = (unsigned char*)ft_strjoin_lens(f->t,
		temp, ft_strlen(f->t), ft_strlen(temp));
	free(temp);
	f->pl = ft_strlen(f->t);
	(*str)++;
	if (f->wf < 0)
	{
		f->fl = '-';
		f->wf *= -1;
	}
	return (1);
}

int		unsigoct_specifier(char **str, va_list *app, t_format *f)
{
	unsigned char	*temp;

	temp = NULL;
	temp = (unsigned char*)ft_itoa_base(va_arg(*app, unsigned int), 'o');
	f->t = (unsigned char*)ft_strjoin_lens(f->t,
		temp, ft_strlen(f->t), ft_strlen(temp));
	free(temp);
	f->pl = ft_strlen(f->t);
	(*str)++;
	if (f->wf < 0)
	{
		f->fl = '-';
		f->wf *= -1;
	}
	return (1);
}

int		unsighex_lit_specifier(char **str, va_list *app, t_format *f)
{
	unsigned char	*temp;

	temp = NULL;
	temp = (unsigned char*)ft_itoa_base(va_arg(*app, unsigned int), 'x');
	f->t = (unsigned char*)ft_strjoin_lens(f->t,
		temp, ft_strlen(f->t), ft_strlen(temp));
	free(temp);
	f->pl = ft_strlen(f->t);
	(*str)++;
	if (f->wf < 0)
	{
		f->fl = '-';
		f->wf *= -1;
	}
	return (1);
}

int		unsighex_big_specifier(char **str, va_list *app, t_format *f)
{
	unsigned char	*temp;

	temp = NULL;
	temp = (unsigned char*)ft_itoa_base(va_arg(*app, unsigned int), 'X');
	f->t = (unsigned char*)ft_strjoin_lens(f->t,
		temp, ft_strlen(f->t), ft_strlen(temp));
	free(temp);
	f->pl = ft_strlen(f->t);
	(*str)++;
	if (f->wf < 0)
	{
		f->fl = '-';
		f->wf *= -1;
	}
	return (1);
}
