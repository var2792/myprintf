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
		//printf("Here ft_printf while len = %i, *str = %c\n", len, *str);
		if (*str == '%')
		{//%[flags][width][.precision][length]specifier
			temp = format_specifier(&str, &ap, &len);
			if (len > 0)
				res = ft_strjoin_free(res, temp, ft_strlen(temp));
			free(temp);
			continue;
		}
		res = ft_strjoin_free(res, str, 1);
		//printf("Here ft_printf while len = %i, res = %s\n", len, res);
		str++;
		len++;
	}
	va_end(ap);
	//printf("End of ft_printf is: len = %i, strlen = %lu\n", len, ft_strlen(res));
	if (len > 0)
		write(1, res, len);
	free(res);
	return(len);
}
