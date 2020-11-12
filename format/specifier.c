/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 15:48:23 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/12 15:48:26 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "format_specifier.h"

char	*specifier(char **str, va_list *app, int *len, t_format *format)
{//cspdiuxX%
	char *s;
	format->specifier = **str;
	if (format->specifier ==  'c' || format->specifier ==  's')
	{
		s = malloc(sizeof(char) * 5);
		s[0] = 'c'; s[1] = 'h'; s[2] = 'a'; s[3] = 'r'; s[4] = '\0';
		return(s);
	}
	if (format->specifier ==  'p')
	{
			s = malloc(sizeof(char) * 8);
			s[0] = 'p'; s[1] = 'o'; s[2] = 'i'; s[3] = 'n'; s[4] = 't'; s[5] = 'e'; s[6] = 'r'; s[7] = '\0';
			return(s);
	}
	if (format->specifier ==  'd' || format->specifier ==  'i' || format->specifier ==  'u')
	{
			s = malloc(sizeof(char) * 7);
			s[0] = 'n'; s[1] = 'u'; s[2] = 'm'; s[3] = 'b'; s[4] = 'e'; s[5] = 'r'; s[6] = '\0';
			return(s);
	}
	if (format->specifier ==  'x' || format->specifier ==  'X')
	{
			s = malloc(sizeof(char) * 5);
			s[0] = 'b'; s[1] = 'a'; s[2] = 's'; s[3] = 'e'; s[4] = '\0';
			return(s);
	}
	*len = -1;
	return (NULL);
}
