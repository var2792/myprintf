/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 15:16:14 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/22 15:16:18 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_specifier.h"

void	null_format(t_format *format)
{
	format->flags = 0;
	format->precision = 0;
	format->width = NULL;
	format->wid_pre = 0;
	format->wid_fls = 0;
	format->specifier = 0;
	format->result = NULL;
	format->print_len = -1;
	format->help = NULL;
	format->success = 1;
	format->isspase = 0;
}

void	print_format(t_format *format)
{
	printf("\n----------------------------\nflags |%c|\n", format->flags);
	printf("precision |%c|\n", format->precision);
	printf("width |%s|\n", format->width);
	printf("wid_pre |%li|\n", format->wid_pre);
	printf("wid_fls |%li|\n", format->wid_fls);
	printf("specifier |%c|\n", format->specifier);
	printf("result |%s|\n", format->result);
	printf("plen |%li| =? %li\n", format->print_len, ft_strlen(format->help));
	printf("help |%s|\n", format->help);
	printf("success |%i|\n\n", format->success);
}

void	*format_specifier(char **str, va_list *app, int *len)
{
	t_format	format;

	(*str)++;
	null_format(&format);
	while (**str == 32 && **str != '\0')
	{
		format.isspase = 1;
		(*str)++;
	}
	while (ft_findchr("-01234567890*", **str) > 0)
	{
		if (ft_findchr("-0", **str) > 0 && format.success)
			format.success = f_flags(str, &format);
		if (ft_findchr("1234567890*", **str) > 0 && format.success)
			format.success = f_width(str, app, &format, 'f');
	}
	if (ft_findchr(".", **str) > 0 && format.success)
		format.success = f_precision(str, &format);
	if (ft_findchr("1234567890*", **str) > 0 &&
			(format.success || format.success == -1))
		format.success = f_width(str, app, &format, 'p');
	if (ft_findchr("cspdiuxXo%", **str) > 0 && format.success)
		format.success = f_specifier(str, app, &format);
	//print_format(&format);
	return (result_char(len, &format));
}
