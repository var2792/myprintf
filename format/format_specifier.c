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
	format->flags = 0; //-0*
	format->precision = 0; //.*
	format->width = NULL; //char num
	format->wid_pre = 0; //int num
	format->wid_fls = 0; //int num
	format->specifier = 0; //cspdiuxX%
	format->result = NULL; //result of ap
	format->print_len = -1; //len of res
	format->help = NULL; //something
	format->success = -1; //right - 1, not - 0, warning - 2
}

void	print_format(t_format *format)
{
	printf("\n-----------------------------------\nflags |%c|\n", format->flags);
	printf("precision |%c|\n", format->precision);
	printf("width |%s|\n", format->width);
	printf("wid_pre |%u|\n", format->wid_pre);
	printf("wid_fls |%u|\n", format->wid_fls);
	printf("specifier |%c|\n", format->specifier);
	printf("result |%s|\n", format->result);
	printf("print_len |%li| =? %li\n", format->print_len, ft_strlen(format->help));
	printf("help |%s|\n", format->help);
	printf("success |%i|\n\n", format->success); //right - 1, not - 0, warning - 2
}

char	*format_specifier(char **str, va_list *app, int *len)
{
	t_format	format;

	(*str)++;
	null_format(&format);
	//printf("Here format_specifier *str = %c len = %i\n", **str, *len);
	//printf("Here format_specifier result = %s\n", format.result);

	if (ft_findchr("-0", **str) > 0 && (format.success || format.success == -1))
		format.success = f_flags(str, &format);

	if (ft_findchr("1234567890*", **str) > 0 && (format.success || format.success == -1))
		format.success = f_width(str, app, &format, 'f');

	if (ft_findchr(".", **str) > 0 && (format.success || format.success == -1) && (format.flags == 0 || format.flags == '-'))
		format.success = f_precision(str, &format);

	if (ft_findchr("1234567890*", **str) > 0 && (format.success || format.success == -1))
		format.success = f_width(str, app, &format, 'p');
	//printf("Here format_specifier width = %i\n", format.wid_pre);

	if (ft_findchr("cspdiuxX", **str) > 0 && (format.success || format.success == -1))
		format.success = f_specifier(str, app, &format);
	//printf("Here format_specifier len = %s\n", format.help);
	//print_format(&format);
	return(result_char(len, &format));
}
