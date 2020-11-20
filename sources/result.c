/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:21:23 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/20 14:30:36 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_specifier.h"

void	not_null(t_format *format, int fl, int *len)
{
	if (format->help != NULL)
	{
		if (fl == 0)
			format->result = format->help;
		*len += format->print_len;
	}
	if (format->print_len == 0 && fl == 0)
		format->result = format->help;
}

int	if_null(t_format *format)
{
	if (format->help == NULL || (format->help[0] == '0' && format->wid_pre >= 0 && format->specifier == 's'))
	{
		if (format->precision == '.' && format->wid_pre < 6)
		{
			format->help = ft_strjoin_lens(format->help, " ", 0, 0);
			format->print_len = 0;
			return (0);
		}
		else
		{
			format->help = ft_strjoin_lens(format->help, "(null)", 0, 6);
			format->print_len = 6;
		}
	}
	return (1);
}

void	*result_char(int *len, t_format *format)
{
	int fl;

	fl = 0;
	if (format->success == 1)
	{
		if (if_null(format))
		{
			/*printf("fl is %i<---\n", fl);
			printf("f->pl is %li<---\n", format->print_len);
			printf("f->h |%s|<---\n", format->help);
			printf("f->res |%s|<---\n\n", format->result);*/
			if (format->flags == '0' || format->precision == '.')
				fl = out_zero(format);
			if (format->flags == '-')
				fl = out_minus(format);
		}
		if ((!format->flags && format->wid_fls != 0) || fl == -1)
			fl = out_without(format);
		not_null(format, fl, len);
		/*printf("fl is %i<---\n", fl);
		printf("f->pl is %li<---\n", format->print_len);
		printf("f->h |%s|<---\n", format->help);
		printf("f->res |%s|<---\n\n", format->result);*/
		return (format->result);
	}
	if (format->success == 2)
	{
		format->result = format->help;
		*len += format->print_len;
		return (format->result);
	}
	*len = -1;
	return (NULL);
}
