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

#include "libtemp.h"

typedef struct	s_format
{//%[flags][width][.precision][length]specifier
	char			flags; //-0*
	char			*width; //char num
	unsigned int	wid_fls; //int num
	unsigned int	wid_pre; //int num
	char			precision; //.*
	//char	*length;
	char			specifier; //cspdiuxX%
	char			*result; //result of ap
	long int		print_len; //len of res
	char			*help; //something
	int				success; //right or not?
}				t_format;

char    *format_specifier(char **str, va_list *app, int *len);
int		f_flags(char **str, t_format *format);
int		f_precision(char **str, t_format *format);
int		f_width(char **str, va_list *app, t_format *format, char flag);
int		f_specifier(char **str, va_list *app, t_format *format);
char 	*result_char(int *len, t_format *format);
int		out_zero(t_format *format);
int		out_minus(t_format *format);
int		out_minus_point(t_format *format);
int		out_without(t_format *format);

#endif
