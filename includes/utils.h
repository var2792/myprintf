/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 19:05:22 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/23 19:05:24 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "libtemp.h"

int				integer_specifier(char **str, va_list *app, t_format *format);
int				unsigint_specifier(char **str, va_list *app, t_format *format);
int				unsigoct_specifier(char **str, va_list *app, t_format *format);
int				unsighex_lit_specifier(char **str, va_list *app,
	t_format *format);
int				unsighex_big_specifier(char **str, va_list *app,
	t_format *format);
int				out_other_zero(t_format *f);
int				negat_zero_num(t_format *f, unsigned char *temp, int i);
int				out_point_zero(t_format *f);
int				char_specifier(char **str, va_list *app, t_format *f);
int				string_specifier(char **str, va_list *app, t_format *f);
int				pointer_specifier(char **str, va_list *app, t_format *f);
int				percent_specifier(char **str, t_format *f);

#endif
