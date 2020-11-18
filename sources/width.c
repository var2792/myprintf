/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:21:32 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/17 22:14:36 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_specifier.h"

static int	width_star(char **str, va_list *app, t_format *format, char flag)
{
	int len;

	len = va_arg(*app, unsigned int);
	if (flag == 'p')
		format->wid_pre = len;
	else if (flag == 'f')
		format->wid_fls = len;
	else
		return (0);
	(*str)++;
	return (1);
}

int			f_width(char **str, va_list *app, t_format *format, char flag)
{
	if (format->print_len == -1)
		format->print_len = 0;
	if (**str == '*')
		return (width_star(str, app, format, flag));
	while (**str > 47 && **str < 58)
	{
		format->width = (char*)ft_strjoin_free(format->width, *str, 1);
		(*str)++;
	}
	if (format->width != NULL)
	{
		if (flag == 'p')
			format->wid_pre = ft_atoi(format->width);
		if (flag == 'f')
			format->wid_fls = ft_atoi(format->width);
		free(format->width);
		format->width = NULL;
		return (1);
	}
	return (0);
}
