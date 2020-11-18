/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:21:23 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/17 22:15:03 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_specifier.h"

void	*result_char(int *len, t_format *format)
{
	int fl;

	fl = 0;
	if (format->success > 0)
	{
		if (format->flags == '0' || format->precision == '.')
			fl = out_zero(format);
		if (format->flags == '-')
			fl = out_minus(format);
		if ((!format->flags && !format->precision) || fl == -1)
			fl = out_without(format);
		if (fl == 0)
			format->result = format->help;
		*len += format->print_len;
		return (format->result);
	}
	*len = -1;
	return (NULL);
}
