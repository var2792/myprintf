/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:20:53 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/17 22:16:13 by tarneld          ###   ########.fr       */
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
	format->success = -1;
}

void	print_format(t_format *format)
{
	printf("\n----------------------------\nflags |%c|\n", format->flags);
	printf("precision |%c|\n", format->precision);
	printf("width |%s|\n", format->width);
	printf("wid_pre |%u|\n", format->wid_pre);
	printf("wid_fls |%u|\n", format->wid_fls);
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
	if (ft_findchr("-0", **str) > 0 && (format.success || format.success == -1))
		format.success = f_flags(str, &format);
	if (ft_findchr("1234567890*", **str) > 0 &&
			(format.success || format.success == -1))
		format.success = f_width(str, app, &format, 'f');
	if (ft_findchr(".", **str) > 0 &&
			(format.success || format.success == -1) &&
			(format.flags == 0 || format.flags == '-'))
		format.success = f_precision(str, &format);
	if (ft_findchr("1234567890*", **str) > 0 &&
			(format.success || format.success == -1))
		format.success = f_width(str, app, &format, 'p');
	if (ft_findchr("cspdiuxX%", **str) > 0 &&
			(format.success || format.success == -1))
		format.success = f_specifier(str, app, &format);
	//print_format(&format);
	return (result_char(len, &format));
}
