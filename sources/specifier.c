/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:21:29 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/18 23:05:42 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_specifier.h"

int		f_specifier(char **str, va_list *app, t_format *format)
{
	unsigned char	*temp;
	unsigned char	*p;
	unsigned char	up;

	format->specifier = **str;
	if (format->print_len == -1)
		format->print_len = 0;
	if (format->specifier == 'c')
	{
		up = (unsigned char)va_arg(*app, int);
		format->help = (unsigned char*)ft_strjoin_lens(format->help,  &up, ft_strlen(format->help), 1);
		format->print_len = 1;
		(*str)++;
		return (1);
	}
	if (format->specifier == 's')
	{
		temp = NULL;
		p = va_arg(*app, unsigned char*);
		temp = (unsigned char*)ft_strjoin_lens(temp, p, ft_strlen(temp), ft_strlen(p));
		format->help = (unsigned char*)ft_strjoin_lens(format->help, temp, ft_strlen(format->help), ft_strlen(temp));
		free(temp);
		format->print_len = ft_strlen(format->help);
		(*str)++;
		return (1);
	}
	if (format->specifier == 'd' || format->specifier == 'i')
	{
		temp = (unsigned char*)ft_itoa_base(va_arg(*app, int), 'A');
		format->help = (unsigned char*)ft_strjoin_lens(format->help, temp, ft_strlen(format->help), ft_strlen(temp));
		free(temp);
		format->print_len = ft_strlen(format->help);
		(*str)++;
		return (1);
	}
	if (format->specifier == 'u')
	{
		temp = (unsigned char*)ft_itoa_base(va_arg(*app, unsigned int), 'A');
		format->help = (unsigned char*)ft_strjoin_lens(format->help, temp, ft_strlen(format->help), ft_strlen(temp));
		free(temp);
		format->print_len = ft_strlen(format->help);
		(*str)++;
		return (1);
	}
	if (format->specifier == 'X')
	{
		temp = (unsigned char*)ft_itoa_base(va_arg(*app, int), 'X');
		format->help = (unsigned char*)ft_strjoin_lens(format->help, temp, ft_strlen(format->help), ft_strlen(temp));
		free(temp);
		format->print_len = ft_strlen(format->help);
		(*str)++;
		return (1);
	}
	if (format->specifier == 'x')
	{
		temp = (unsigned char*)ft_itoa_base(va_arg(*app, int), 'x');
		format->help = (unsigned char*)ft_strjoin_lens(format->help, temp, ft_strlen(format->help), ft_strlen(temp));
		free(temp);
		format->print_len = ft_strlen(format->help);
		(*str)++;
		return (1);
	}
	if (format->specifier == 'p')
	{
		p = malloc(sizeof(char) * 3);
		p[0] = '0';
		p[1] = 'x';
		p[2] = '\0';
		temp = (unsigned char*)ft_itoa_base(va_arg(*app, long int), 'x');
		p = (unsigned char*)ft_strjoin_lens(p, temp, ft_strlen(p), ft_strlen(temp));
		format->help = (unsigned char*)ft_strjoin_lens(format->help, p, ft_strlen(format->help), ft_strlen(p));
		free(temp);
		free(p);
		format->print_len = ft_strlen(format->help);
		(*str)++;
		return (1);
	}
	if (format->specifier == '%')
	{
		temp = NULL;
		p = malloc(sizeof(char) * 2);
		p[0] = '%';
		p[1] = '\0';
		temp = (unsigned char*)ft_strjoin_lens(temp, p, ft_strlen(temp), 1);
		format->help = (unsigned char*)ft_strjoin_lens(format->help, temp, ft_strlen(format->help), ft_strlen(temp));
		free(temp);
		free(p);
		format->print_len = ft_strlen(format->help);
		(*str)++;
		return (2);
	}
	return (0);
}
