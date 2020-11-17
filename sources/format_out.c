/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:10:46 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/17 01:10:46 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_specifier.h"

int		out_zero(t_format *format)
{
	long int	size;
	int 		i;
	char		*temp;

	i = 0;
	temp = NULL;
	size = (format->flags == '0') ? format->wid_fls : format->wid_pre;
	if (format->print_len >= size)
		return (0);
	if (format->specifier == 'c' || format->specifier == 's')
		return (-1);
	while (i + format->print_len < size)
	{
		temp = ft_strjoin_free(temp, "0", 1);
		i++;
	}
	format->result = ft_strjoin_free(temp, format->help, format->print_len);
	free(format->help);
	format->print_len += i;
	return (1);
}

int		out_minus_point(t_format *format)
{
	long int	size;
	int 		i;
	char		*temp;

	i = 0;
	temp = NULL;
	size = format->wid_fls;
	if (format->print_len >= size)
		return (0);
	while (i + format->print_len < size)
	{
		temp = ft_strjoin_free(temp, " ", 1);
		i++;
	}
	format->result = ft_strjoin_free(format->result, temp, format->print_len);
	free(temp);
	format->print_len += i;
	return (1);
}

int		out_minus(t_format *format)
{
	long int	size;
	int 		i;
	char		*temp;

	i = 0;
	temp = NULL;
	size = format->wid_fls;
	if (format->precision == '.')
		return (out_minus_point(format));
	if (format->print_len >= size)
		return (0);
	while (i + format->print_len < size)
	{
		temp = ft_strjoin_free(temp, " ", 1);
		i++;
	}
	format->result = ft_strjoin_free(format->help, temp, i);
	free(temp);
	format->print_len += i;
	return (1);
}

int		out_without(t_format *format)
{
	long int	size;
	int 		i;
	char		*temp;

	i = 0;
	temp = NULL;
	size = format->wid_fls;
	if (format->print_len >= size)
		return (0);
	while (i + format->print_len < size)
	{
		temp = ft_strjoin_free(temp, " ", 1);
		i++;
	}
	format->result = ft_strjoin_free(temp, format->help, format->print_len);
	free(format->help);
	format->print_len += i;
	return (1);
}
