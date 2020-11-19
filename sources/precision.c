/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:21:20 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/17 13:43:35 by tarneld          ###   ########.fr       */
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
