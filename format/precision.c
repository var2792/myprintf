/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 11:38:57 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/16 11:38:57 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_specifier.h"

int		f_precision(char **str, t_format *format)
{//.
	format->precision = **str;
    if (format->print_len == -1)
	    format->print_len = 0;
	if (format->precision ==  '.')
	{
		//format->help = ft_strjoin_free(format->help, "point ", 6);
		//format->print_len = ft_strlen(format->help);
		(*str)++;
		return(1);
	}
	return (0);
}
