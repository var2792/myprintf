# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tarneld <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/12 16:14:57 by tarneld           #+#    #+#              #
#    Updated: 2020/11/12 16:14:59 by tarneld          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_printf.c format/format_specifier.c format/specifier.c format/format_out.c format/flags.c format/width.c format/result.c format/precision.c libtemp/ft_strjoin.c libtemp/ft_findchr.c libtemp/ft_strlen.c libtemp/ft_atoi.c libtemp/ft_itoa.c

OBJS		=	${SRCS:.c=.o}

HEADER		= -I ft_printf.h format/format_specifier.c.h libtemp/libtemp.h

CFLAGS		= -Wall -Werror -Wextra

CC			= gcc

.c.o:		${HEADER}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

RM			= @rm -rf

NAME		= libftprintf.a

clean:
			${RM} ${OBJS} *.gch

${NAME}:	${OBJS}
			@ar rc ${NAME} ${OBJS}
			@ranlib ${NAME}
#clean

all:		 ${NAME}

fclean:		clean
			${RM} ${NAME} a.out

re:			fclean all

.PHONY: 	all clean fclean re
