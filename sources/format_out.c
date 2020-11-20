/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_out.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:20:49 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/20 13:57:27 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/format_specifier.h"

int		out_str_zero(t_format *format)
{
	unsigned int	i;
	unsigned char	*temp;

	i = 0;
	if (format->wid_pre < 0)
		return (0);
	temp = format->help + i;
	while (i < format->wid_pre && temp[0] != 0)
	{
		//printf("temp str is |%s|<---\n", temp);
		format->result = ft_strjoin_lens(format->result, temp, ft_strlen(format->result), 1); //пробелы ли?
		//printf("f->res str is |%s|<---\n", format->result);
		temp = format->help + ++i;
	}
	if (format->wid_pre == 0)
		format->result = ft_strjoin_lens(format->result, temp, ft_strlen(format->result), 0);
	//printf("f->res str is |%s| %i<---\n", format->result, i);
	//printf("f->h str is |%s|<---\n", format->help);
	format->print_len = i;
	free(format->help);
	//free(temp);
	//printf("\ntemp!\n---------------------->>>><<<<----------------------\n\n");
	return (1);
}

int		out_zero(t_format *format)
{
	long int		size;
	int				i;
	unsigned char	*temp;

	i = 0;
	temp = NULL;
	if (ft_strlen(format->help) == 0)
		return (0);
	size = (format->flags == '0') ? format->wid_fls : format->wid_pre;
	if (format->specifier == 's')
		return (out_str_zero(format));
	if (size < 0 || format->print_len >= size)
		return (0);
	if (format->specifier == 'c')
		return (-1);
	while (i + format->print_len < size)
	{
		temp = ft_strjoin_lens(temp, "0", ft_strlen(temp), 1);
		i++;
	}
	format->result = (unsigned char*)ft_strjoin_lens(temp, format->help, ft_strlen(temp), format->print_len);
	format->print_len += i;
	free(format->help);
	return (1);
}

int		out_minus(t_format *format)
{
	long int		size;
	int				i;
	unsigned char	*temp;

	i = 0;
	temp = NULL;
	size = format->wid_fls;
	if (size < 0 || format->print_len >= size)
		return (0);
	while (i + format->print_len < size)
	{
		temp = ft_strjoin_lens(temp, " ", ft_strlen(temp), 1);
		i++;
	}
	if (format->precision == '.')
		format->result = (unsigned char*)ft_strjoin_lens(format->result, temp, ft_strlen(format->result), i);
	else
		format->result = (unsigned char*)ft_strjoin_lens(format->help, temp, ft_strlen(format->help), i);
	//format->help = NULL;
	free(temp);
	format->print_len += i;
	return (1);
}

int		out_without(t_format *format)
{
	long int		size;
	int				i;
	unsigned char	*temp;

	i = 0;
	temp = NULL;
	size = format->wid_fls;
	if (format->print_len > size)
		return (0);
	while (i + format->print_len < size)
	{
		temp = ft_strjoin_lens(temp, " ", ft_strlen(temp), 1);
		i++;
	}
	if (format->precision == '.')
	{
		temp = (unsigned char*)ft_strjoin_lens(temp, format->result, i, ft_strlen(format->result));
		free(format->result);
		format->result = temp;
	}
	else
	{
		format->result = (unsigned char*)ft_strjoin_lens(temp, format->help, i, format->print_len);
		free(format->help);
	}
	format->print_len += i;
	return (1);
}
