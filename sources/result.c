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

void	not_null(t_format *format, int fl, int *len)
{
	unsigned char *sp;

	if (format->help != NULL)
	{
		if ((fl == 0 && format->result == NULL) || (!format->precision && !format->flags && !format->wid_fls))
			format->result = format->help;
		*len += format->print_len;
	}
	if (!format->result && fl == 0)
		format->result = format->help;
	if (format->isspase)
	{
		sp = malloc(2 * sizeof(char));
		sp[0] = 32;
		sp[1] = 0;
		sp = ft_strjoin_lens(sp, format->result, 1, format->print_len);
		free(format->result);
		format->result = sp;
		*len += 1;
	}
}

void	if_null(t_format *format)
{
	if (format->help == NULL || (format->help[0] == '0' && format->wid_pre == 0))
	{
		if (format->precision == '.' && format->wid_pre <= 0)
		{
			format->help = ft_strjoin_lens(format->help, " ", 0, 0);
			format->print_len = 0;
		}
	}
}

void	*result_char(int *len, t_format *format)
{
	int fl;

	fl = 0;
	if (format->success == 1)
	{
		if_null(format);
		if (format->flags == '0' || format->precision == '.')
			fl = out_zero(format);
		if (format->flags == '-')
			fl = out_minus(format);
		if ((!format->flags && format->wid_fls != 0) || fl == -1)
			fl = out_without(format);
		not_null(format, fl, len);
		return (format->result);
	}
	*len = -1;
	return (NULL);
}
