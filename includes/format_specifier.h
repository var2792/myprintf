/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:21:37 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/17 13:27:10 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORMAT_SPECIFIER_H
# define FT_FORMAT_SPECIFIER_H

# include "libtemp.h"

typedef struct	s_format
{
	char			flags;
	char			*width;
	unsigned int	wid_fls;
	unsigned int	wid_pre;
	char			precision;
	char			specifier;
	char			*result; //unsigned - void ??<-----
	long int		print_len;
	char			*help;
	int				success;
}				t_format;

char			*format_specifier(char **str, va_list *app, int *len);
int				f_flags(char **str, t_format *format);
int				f_precision(char **str, t_format *format);
int				f_width(char **str, va_list *app, t_format *format, char flag);
int				f_specifier(char **str, va_list *app, t_format *format);
char			*result_char(int *len, t_format *format);
int				out_zero(t_format *format);
int				out_minus(t_format *format);
int				out_minus_point(t_format *format);
int				out_without(t_format *format);

#endif
