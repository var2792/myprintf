/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:08:50 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/22 17:08:55 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_specifier.h"

int	f_precision(char **str, t_format *format)
{
	format->precision = **str;
	if (format->print_len == -1)
		format->print_len = 0;
	if (format->precision == '.')
	{
		(*str)++;
		return (1);
	}
	return (0);
}
