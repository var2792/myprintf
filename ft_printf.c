/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:11:39 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/19 01:05:11 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_devide(unsigned char **res, char **str, va_list *app, int *len)
{
	unsigned char	*temp;
	int				len_t;

	//printf("len is %i<---\n",  *len);
	temp = (unsigned char*)format_specifier(str, app, len);
	len_t = (temp[0] == 0 && ft_strlen(*res) != (size_t)(*len)) ? 1 : ft_strlen(temp);
	if (*len > 0)
		*res = (unsigned char*)ft_strjoin_lens(*res, temp, *len - ft_strlen(temp), len_t);
	*len = ((temp[0] == 0) && (ft_strlen(temp) > 0)) ? *len + 1 : *len;
	if (*res != temp)
		free(temp);
}

int		ft_printf(const char *orig, ...)
{
	va_list			ap;
	char			*str;
	unsigned char	*res;
	int				len;

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
			//printf("len is %i<---\n",  len);
			res = (unsigned char*)ft_strjoin_lens(res, str, len, 1);
			str++;
			len++;
		}
		//printf("---------->*str {%c}<---\n",  *str);
		//printf("res is {%s}<---\n", res);
	}
	va_end(ap);
	if (len > 0)
		write(1, res, len);
	free(res);
	return (len);
}
