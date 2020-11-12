/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:48:23 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/12 15:48:26 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_specifier.h"

char	*specifier(char **str, va_list *app, int *len, t_format *format)
{//cspdiuxX%
	format->specifier = **str;
	
	//*len = -1;
	return (NULL);
}
