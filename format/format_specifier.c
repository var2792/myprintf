/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:14:27 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/12 13:14:33 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_specifier.h"

void	null_format(t_format *format)
{
	format->flags = 0;
	format->width = NULL;
	format->precision = NULL;
	//format->length = NULL;
	format->specifier = 0;
	format->result = NULL;
	format->print_len = 0;
	format->help = 0;
	format->success = 0;
}

char	*format_specifier(char **str, va_list *app, int *len)
{
	char		*res;
	t_format	format;

	(*str)++;
	printf("FS *str = %c\n", **str);
	null_format(&format);
	if (ft_findchr("cspdiuxX", **str) > 0)
		res = specifier(str, app, len, &format);
	return (res);
}
