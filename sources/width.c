/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:39:08 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/16 11:39:08 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_specifier.h"

int		f_width(char **str, va_list *app, t_format *format, char flag)
{//1234567890*
	int len;

    if (format->print_len == -1)
	    format->print_len = 0;
	if (**str == '*')
	{
		len = va_arg(*app, unsigned int);
		if (flag == 'p')
			format->wid_pre = len;
		if (flag == 'f')
			format->wid_fls = len;
		(*str)++;
		return(1);
	}
	while (**str > 47 && **str < 58)
    {
        format->width = ft_strjoin_free(format->width, *str, 1);
		(*str)++;
    }
    if (format->width !=  NULL && flag == 'p')
	{
		format->wid_pre = ft_atoi(format->width);
		//format->help = ft_strjoin_free(format->help, format->width, ft_strlen(format->width));
		//format->print_len = ft_strlen(format->help);
		free(format->width);
		format->width = NULL;
		return(1);
	}
    if (format->width !=  NULL && flag == 'f')
	{
		format->wid_fls = ft_atoi(format->width);
		//format->help = ft_strjoin_free(format->help, format->width, ft_strlen(format->width));
		//format->print_len = ft_strlen(format->help);
		free(format->width);
		format->width = NULL;
		return(1);
	}
	return (0);
}
