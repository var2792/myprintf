/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:38:43 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/16 11:38:43 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_specifier.h"

int		f_flags(char **str, t_format *format)
{//-0
	format->flags = **str;
    if (format->print_len == -1)
	    format->print_len = 0;
	if (format->flags ==  '-')
	{
		//format->help = ft_strjoin_free(format->help, "minus ", 6);
		//format->print_len = ft_strlen(format->help);
		(*str)++;
		return(1);
	}
	if (format->flags ==  '0')
	{
		//format->help = ft_strjoin_free(format->help, "zero ", 5);
		//format->print_len = ft_strlen(format->help);
		(*str)++;
		return(1);
	}
	return (0);
}
