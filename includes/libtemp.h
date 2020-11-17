/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtemp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:51:23 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/12 16:51:25 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTEMP_H
# define LIBTEMP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

char	*ft_strjoin_free(char *s1, char const *s2, int len);
int		ft_findchr(const char *st, char c);
size_t		ft_strlen(const char *str);
char		*ft_itoa_base(long int value, char base); //10 - A, 16 - x or X
int			ft_atoi(const char *str);


#endif
