/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:49:29 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/12 15:49:32 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORMAT_SPECIFIER_H
# define FT_FORMAT_SPECIFIER_H

#include "../ft_printf.h"
#include "../libtemp/libtemp.h"

typedef struct	s_format
{//%[flags][width][.precision][length]specifier
	char	flags; //-0*
	char	*width; //num
	char	*precision; //.*
	//char	*length;
	char	specifier; //cspdiuxX%
	char	*result; //result of ap
	int		print_len; //len of res
	int		help; //something
	int		success; //right or not?
}				t_format;

char	*specifier(char **str, va_list *app, int *len, t_format *format);

#endif
