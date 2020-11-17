/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:21:29 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/17 13:57:00 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_specifier.h"

int		f_specifier(char **str, va_list *app, t_format *format)
{
	char			*temp;
	char	*p;
	int		up;

	format->specifier = **str;
	if (format->print_len == -1)
		format->print_len = 0;
	if (format->specifier == 'c')
	{
		temp = NULL;
		up = va_arg(*app, int);
		//printf("Here %i\n", up);
		temp = ft_strjoin_one(temp, up, 1);
		//printf("Here %s\n", temp);
		format->help = ft_strjoin_free(format->help, temp, ft_strlen(temp));
		free(temp);
		format->print_len = ft_strlen(format->help);
		(*str)++;
		return (1);
	}
	if (format->specifier == 's')
	{
		temp = NULL;
		p = va_arg(*app, char*);
		temp = ft_strjoin_free(temp, p, ft_strlen(p));
		format->help = ft_strjoin_free(format->help, temp, ft_strlen(temp));
		free(temp);
		format->print_len = ft_strlen(format->help);
		(*str)++;
		return (1);
	}
	if (format->specifier == 'd' || format->specifier == 'i')
	{
		temp = ft_itoa_base(va_arg(*app, int), 'A');
		format->help = ft_strjoin_free(format->help, temp, ft_strlen(temp));
		free(temp);
		format->print_len = ft_strlen(format->help);
		(*str)++;
		return (1);
	}
	if (format->specifier == 'u')
	{
		temp = ft_itoa_base(va_arg(*app, unsigned int), 'A');
		format->help = ft_strjoin_free(format->help, temp, ft_strlen(temp));
		free(temp);
		format->print_len = ft_strlen(format->help);
		(*str)++;
		return (1);
	}
	if (format->specifier == 'X')
	{
		temp = ft_itoa_base(va_arg(*app, int), 'X');
		format->help = ft_strjoin_free(format->help, temp, ft_strlen(temp));
		free(temp);
		format->print_len = ft_strlen(format->help);
		(*str)++;
		return (1);
	}
	if (format->specifier == 'x')
	{
		temp = ft_itoa_base(va_arg(*app, int), 'x');
		format->help = ft_strjoin_free(format->help, temp, ft_strlen(temp));
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
		temp = ft_itoa_base(va_arg(*app, long int), 'x');
		p = ft_strjoin_free(p, temp, ft_strlen(temp));
		format->help = ft_strjoin_free(format->help, p, ft_strlen(p));
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
		temp = ft_strjoin_free(temp, p, 1);
		format->help = ft_strjoin_free(format->help, temp, ft_strlen(temp));
		free(temp);
		free(p);
		format->print_len = ft_strlen(format->help);
		(*str)++;
		return (1);
	}
	return (0);
}
