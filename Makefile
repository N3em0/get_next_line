# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 14:29:30 by egache            #+#    #+#              #
#    Updated: 2025/01/24 15:47:53 by egache           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEAD	=	get_next_line.h

NAME	=	libftgnl.a

EXE		=	get_next_line

SRCS	=	get_next_line.c\
			get_next_line_utils.c\

#MAIN	=	main.c

OBJS	=	${SRCS:%.c=%.o}

CC	=	cc

AR	=	ar -rc

FLAGS	=	-Wall -Wextra -Werror

all	:	${NAME}

${OBJS} :   %.o : %.c ${HEAD} Makefile
	${CC} ${FLAGS} -c $< -o $@

#${EXE}	:	${OBJS}
#	${CC} ${FLAGS} ${OBJS} ${MAIN} -o ${EXE}

${NAME}	:	${OBJS}
	${AR} ${NAME} ${OBJS}

#exe	:	${EXE}

clean	:
	rm -rf ${OBJS}

fclean	:	clean
	rm -f ${NAME} ${EXE}
re	:	fclean all

.PHONY	:	all clean fclean re
