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

SRCS		= ft_printf.c \
			format/format_specifier.c \
			format/specifier.c \
			libtemp/ft_strjoin.c
			libtemp/ft_findchr.c

OBJS		=	${SRCS:.c=.o}

HEADER		= -I ft_printf.h \
			format/format_specifier.c.h \
			libtemp/libtemp.h

CFLAGS		= -Wall -Wextra -Werror

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
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re
