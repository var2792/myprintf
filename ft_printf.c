/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:29:14 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/11 18:29:18 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *orig, ...)
{
	va_list	ap;
	char	*str;
	char	*res;
	char	*temp;
	int		len;

	len = 0;
	res = NULL;
	str = (char*)orig;
	va_start(ap, orig);
	while (*str && len >= 0)
	{
		if (*str == '%')
		{//%[flags][width][.precision][length]specifier
			write(1, "spec-", 5);
			temp = format_specifier(&str, &ap, &len);
			res = ft_strjoin_free(res, temp);
			free(temp);
			continue;
		}
		res = ft_strjoin_free(res, str);
		str++;
		len++;
	}
	return(len);
}
