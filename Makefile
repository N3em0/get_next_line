# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egache <egache@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/24 14:29:30 by egache            #+#    #+#              #
#    Updated: 2025/01/31 01:04:18 by egache           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HEAD			:=	get_next_line.h

NAME			:=	libgnl.a

SRC				=				\
	get_next_line.c				\
	get_next_line_utils.c		\

SRC_DIR			:=	src
SRC				:=	$(SRC:%=$(SRC_DIR)/%)

BUILD_DIR		:=	.build
OBJ				:=	$(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEP				:=	$(OBJ:%.o=.d)

CC				:=	cc

AR				:=	ar -rcs

CFLAGS			:=	-Wall -Wextra -Werror

MAKEFLAGS		+=	--no-print-directory

INCLUDE			:=	-MMD -MP -Iinclude

DIR_DUP			=	mkdir -p $(@D)

RM				:=	rm -f

RMF				:=	rm -rf

all				:	$(NAME)

$(NAME)			:	$(OBJ)
			$(AR) $(NAME) $(OBJ)
			$(info CREATED $(NAME))

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
			$(DIR_DUP)
			$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<
			$(info CREATED $@)

-include	$(DEP)

clean 			:
			$(RMF) $(BUILD_DIR)

fclean			:	clean
			$(RM) $(NAME)

re				:
			$(MAKE) fclean
			$(MAKE) all

.PHONY			:	all clean fclean re

.silent			:
