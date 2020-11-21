/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:21:29 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/20 14:27:55 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_specifier.h"

int		char_specifier(char **str, va_list *app, t_format *format)
{
	unsigned char	up;

	up = (unsigned char)va_arg(*app, int);
	format->help = (unsigned char*)ft_strjoin_lens(format->help,  &up, ft_strlen(format->help), 1);
	format->print_len = 1;
	(*str)++;
	return (1);
}

int		string_specifier(char **str, va_list *app, t_format *format)
{
	unsigned char	*temp;
	unsigned char	*p;

	temp = NULL;
	p = va_arg(*app, unsigned char*);
	if (p == NULL) //связь с result.c c 37-41
	{
		p = ft_strjoin_lens(p, "(null)", 0, 6);
		temp = (unsigned char*)ft_strjoin_lens(temp, p, ft_strlen(temp), ft_strlen(p));
		free(p);
	}
	else
		temp = (unsigned char*)ft_strjoin_lens(temp, p, ft_strlen(temp), ft_strlen(p));
	format->help = (unsigned char*)ft_strjoin_lens(format->help, temp, ft_strlen(format->help), ft_strlen(temp));
	free(temp);
	format->print_len = ft_strlen(format->help);
	(*str)++;
	if (format->wid_fls < 0)
	{
		format->flags = '-';
		format->wid_fls *= -1;
	}
	return (1);
}

int		pointer_specifier(char **str, va_list *app, t_format *format)
{
	unsigned char	*temp;
	unsigned char	*p;
	long int		num_p;

	temp = NULL;
	num_p = va_arg(*app, long int);
	/*if (num_p <= 0)
	{
		format->help = (unsigned char*)ft_strjoin_lens(format->help, "(nil)", ft_strlen(format->help), 5);
		format->print_len = ft_strlen(format->help);
		(*str)++;
		return (1);
	}*/
	p = malloc(sizeof(char) * 3);
	p[0] = '0';
	p[1] = 'x';
	p[2] = '\0';
	temp = (unsigned char*)ft_itoa_base(num_p, 'x');
	p = (unsigned char*)ft_strjoin_lens(p, temp, ft_strlen(p), ft_strlen(temp));
	format->help = (unsigned char*)ft_strjoin_lens(format->help, p, ft_strlen(format->help), ft_strlen(p));
	free(temp);
	free(p);
	format->print_len = ft_strlen(format->help);
	(*str)++;
	return (1);
}

int		percent_specifier(char **str, t_format *format)
{
	unsigned char	*temp;

	temp = NULL;
	format->help = (unsigned char*)ft_strjoin_lens(format->help, "%", ft_strlen(format->help), 1);
	free(temp);
	format->print_len = ft_strlen(format->help);
	(*str)++;
	return (1);
}

int		f_specifier(char **str, va_list *app, t_format *format)
{
	format->specifier = **str;
	if (format->print_len == -1)
		format->print_len = 0;
	if (format->specifier == 'c')
		return (char_specifier(str, app, format));
	if (format->specifier == 's')
		return (string_specifier(str, app, format));
	if (format->specifier == 'p')
		return (pointer_specifier(str, app, format));
	if (format->specifier == '%')
		return (percent_specifier(str, format));
	if (format->specifier == 'd' || format->specifier == 'i')
		return (integer_specifier(str, app, format));
	if (format->specifier == 'u')
		return (unsigint_specifier(str, app, format));
	if (format->specifier == 'X')
		return (unsighex_big_specifier(str, app, format));
	if (format->specifier == 'x')
		return (unsighex_lit_specifier(str, app, format));
	if (format->specifier == 'o')
		return (unsigoct_specifier(str, app, format));
	return (0);
}
