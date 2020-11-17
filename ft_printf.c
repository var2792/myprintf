/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:11:39 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/17 13:13:51 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_devide(char **res, char **str, va_list *app, int *len)
{
	char	*temp;

	temp = format_specifier(str, app, len);
	if (*len > 0)
		*res = ft_strjoin_free(*res, temp, ft_strlen(temp));
	free(temp);
}

int		ft_printf(const char *orig, ...)
{
	va_list	ap;
	char	*str;
	char	*res;
	int		len;

	len = 0;
	res = NULL;
	str = (char*)orig;
	va_start(ap, orig);
	while (*str && len >= 0)
	{
		if (*str == '%')
			format_devide(&res, &str, &ap, &len);
		else
		{
			res = ft_strjoin_free(res, str, 1);
			str++;
			len++;
		}
	}
	va_end(ap);
	if (len > 0)
		write(1, res, len);
	free(res);
	return (len);
}
