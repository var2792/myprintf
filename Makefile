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

SRCS		= ft_printf.c sources/*.c  #sources/format_specifier.c sources/specifier.c sources/format_out.c sources/flags.c sources/width.c sources/result.c sources/precision.c sources/ft_strjoin.c sources/ft_findchr.c sources/ft_strlen.c sources/ft_atoi.c sources/ft_itoa.c

OBJS		=	${SRCS:.c=.o}

HEADER		= -I ft_printf.h includes/*.h  #includes/format_specifier.c.h includes/libtemp.h

CFLAGS		= -Wall -Werror -Wextra

CC			= gcc

.c.o:		${HEADER}
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

RM			= rm -rf

NAME		= libftprintf.a

${NAME}:	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		 ${NAME}

clean:
			${RM} ${OBJS} *.gch

fclean:		clean
			${RM} ${NAME} a.out

re:			fclean all

.PHONY: 	all clean fclean re
