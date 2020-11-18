/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:21:29 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/17 22:14:14 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_specifier.h"

int		f_specifier(char **str, va_list *app, t_format *format)
{
	unsigned char	*temp;
	unsigned char	*p;
	int				up;

	format->specifier = **str;
	if (format->print_len == -1)
		format->print_len = 0;
	if (format->specifier == 'c')
	{
		temp = NULL;
		up = va_arg(*app, int);
		//printf("Here %i\n", up);
		temp = (unsigned char*)ft_strjoin_one(temp, up, 1);
		//printf("Here %s\n", temp);
		format->help = (unsigned char*)ft_strjoin_free(format->help, temp, ft_strlen(temp));
		free(temp);
		format->print_len = ft_strlen(format->help);
		(*str)++;
		return (1);
	}
	if (format->specifier == 's')
	{
		temp = NULL;
		p = va_arg(*app, unsigned char*);
		temp = (unsigned char*)ft_strjoin_free(temp, p, ft_strlen(p));
		format->help = (unsigned char*)ft_strjoin_free(format->help, temp, ft_strlen(temp));
		free(temp);
		format->print_len = ft_strlen(format->help);
		(*str)++;
		return (1);
	}
	if (format->specifier == 'd' || format->specifier == 'i')
	{
		temp = (unsigned char*)ft_itoa_base(va_arg(*app, int), 'A');
		format->help = (unsigned char*)ft_strjoin_free(format->help, temp, ft_strlen(temp));
		free(temp);
		format->print_len = ft_strlen(format->help);
		(*str)++;
		return (1);
	}
	if (format->specifier == 'u')
	{
		temp = (unsigned char*)ft_itoa_base(va_arg(*app, unsigned int), 'A');
		format->help = (unsigned char*)ft_strjoin_free(format->help, temp, ft_strlen(temp));
		free(temp);
		format->print_len = ft_strlen(format->help);
		(*str)++;
		return (1);
	}
	if (format->specifier == 'X')
	{
		temp = (unsigned char*)ft_itoa_base(va_arg(*app, int), 'X');
		format->help = (unsigned char*)ft_strjoin_free(format->help, temp, ft_strlen(temp));
		free(temp);
		format->print_len = ft_strlen(format->help);
		(*str)++;
		return (1);
	}
	if (format->specifier == 'x')
	{
		temp = (unsigned char*)ft_itoa_base(va_arg(*app, int), 'x');
		format->help = (unsigned char*)ft_strjoin_free(format->help, temp, ft_strlen(temp));
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
		p = (unsigned char*)ft_strjoin_free(p, temp, ft_strlen(temp));
		format->help = (unsigned char*)ft_strjoin_free(format->help, p, ft_strlen(p));
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
		temp = (unsigned char*)ft_strjoin_free(temp, p, 1);
		format->help = (unsigned char*)ft_strjoin_free(format->help, temp, ft_strlen(temp));
		free(temp);
		free(p);
		format->print_len = ft_strlen(format->help);
		(*str)++;
		return (1);
	}
	return (0);
}
