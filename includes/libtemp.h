/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtemp.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarneld <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:21:40 by tarneld           #+#    #+#             */
/*   Updated: 2020/11/18 12:47:55 by tarneld          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTEMP_H
# define LIBTEMP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

void		*ft_strjoin_free(void *s1, void *s2, int len);
void		*ft_strjoin_one(void *s1, int s2, int len);
void		*ft_strjoin_lens(void *s1, void *s2, int len1, int len2);
int			ft_findchr(const char *st, char c);
size_t		ft_strlen(void *str);
char		*ft_itoa_base(long int value, char base);
int			ft_atoi(const char *str);

#endif
