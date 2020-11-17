/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:20:44 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/17 13:29:59 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_specifier.h"

int		f_flags(char **str, t_format *format)
{
	format->flags = **str;
	if (format->print_len == -1)
		format->print_len = 0;
	if (format->flags == '-')
	{
		(*str)++;
		return (1);
	}
	if (format->flags == '0')
	{
		(*str)++;
		return (1);
	}
	return (0);
}
