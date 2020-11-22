/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_specifier.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:15:16 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/22 17:15:26 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FORMAT_SPECIFIER_H
# define FT_FORMAT_SPECIFIER_H

# include "libtemp.h"

typedef struct	s_format
{
	char			fl;
	char			*w;
	long int		wf;
	long int		wp;
	char			pr;
	char			sp;
	unsigned char	*re;
	long int		pl;
	unsigned char	*t;
	int				su;
	int				isspase;
}				t_format;

void			*format_specifier(char **str, va_list *app, int *len);
int				f_flags(char **str, t_format *format);
int				f_precision(char **str, t_format *format);
int				f_width(char **str, va_list *app, t_format *format, char flag);
int				f_specifier(char **str, va_list *app, t_format *format);
int				integer_specifier(char **str, va_list *app, t_format *format);
int				unsigint_specifier(char **str, va_list *app, t_format *format);
int				unsigoct_specifier(char **str, va_list *app, t_format *format);
int				unsighex_lit_specifier(char **str, va_list *app,
	t_format *format);
int				unsighex_big_specifier(char **str, va_list *app,
	t_format *format);
void			*result_char(int *len, t_format *format);
int				out_zero(t_format *format);
int				out_minus(t_format *format);
int				out_without(t_format *format);

#endif
