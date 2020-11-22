/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:13:07 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/22 17:13:16 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_specifier.h"

int		integer_specifier(char **str, va_list *app, t_format *format)
{
	unsigned char	*temp;

	temp = NULL;
	temp = (unsigned char*)ft_itoa_base(va_arg(*app, int), 'A');
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

int		unsigint_specifier(char **str, va_list *app, t_format *format)
{
	unsigned char	*temp;

	temp = NULL;
	temp = (unsigned char*)ft_itoa_base(va_arg(*app, unsigned int), 'A');
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

int		unsigoct_specifier(char **str, va_list *app, t_format *format)
{
	unsigned char	*temp;

	temp = NULL;
	temp = (unsigned char*)ft_itoa_base(va_arg(*app, unsigned int), 'o');
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

int		unsighex_lit_specifier(char **str, va_list *app, t_format *format)
{
	unsigned char	*temp;

	temp = NULL;
	temp = (unsigned char*)ft_itoa_base(va_arg(*app, unsigned int), 'x');
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

int		unsighex_big_specifier(char **str, va_list *app, t_format *format)
{
	unsigned char	*temp;

	temp = NULL;
	temp = (unsigned char*)ft_itoa_base(va_arg(*app, unsigned int), 'X');
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
