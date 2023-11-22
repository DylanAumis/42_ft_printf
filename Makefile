# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daumis <daumis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 06:26:22 by dylan             #+#    #+#              #
#    Updated: 2023/07/19 15:02:33 by daumis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_MAIN		=	src/ft_printf.c \
				src/ft_putchar.c \
				src/ft_putstr.c \
				src/ft_handlei.c \
				src/ft_handleu.c \
				src/ft_handlehex.c
SRCS			= ${SRC_MAIN}

OBJ_DIR			= objs
OBJS 			= $(patsubst src/%.c,$(OBJ_DIR)/%.o,$(SRCS))						

CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -I.

NAME			=	libftprintf.a

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): 		$(OBJS)
				@echo "\033[1;35m\n                              ⌛️Compiling files...\033[0m"
				ar rcs $(NAME) $(OBJS)
				@echo "\033[32;1m\n                     Library has compiled successfully! ✅ \033[0m"
				@echo "\033[32;1m\n 📚 Library '$(NAME)' has been created in: \n    └─ 📂 \033[4;36m ~ $(PWD)\033[0m"

clean:
				$(RM) -r $(OBJ_DIR)

fclean:
	@echo "\033[1;33m\n                        [Cleaning directories with \033[0;36mfclean\033[1;33m]\n\033[0m"
	@make clean
	$(RM) $(NAME)

re:	fclean
	make all


.PHONY:		all clean fclean re
