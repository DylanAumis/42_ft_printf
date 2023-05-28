# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dylan <dylan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 06:26:22 by dylan             #+#    #+#              #
#    Updated: 2023/05/28 17:42:10 by dylan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	src/ft_printf.c \
					src/ft_putchar.c \
					src/ft_putstr.c \
					src/ft_handlei.c \
					src/ft_handleu.c \
					src/ft_handlehex.c
						
OBJS			=	$(SRCS:.c=.o)

CC				=	gcc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -I.

NAME			=	libftprintf.a

all:			$(NAME)


$(NAME): 		$(OBJS)
				@echo "\033[1;35m\n                               Compiling files...\n\033[0m"
				ar rcs $(NAME) $(OBJS)
				@echo "\033[32;1m\nProject has compiled successfully! Library './$(NAME)' has been created in: \n    \033[4;34m$(PWD)\033[0m\033[0m\033[0K"

clean:
				$(RM) $(OBJS)

fclean:
	@echo "\033[1;33m\n                        [Cleaning directories with \033[0;36mfclean\033[1;33m]\n\033[0m"
	@make clean
	$(RM) $(NAME)

re:	fclean
	make all


.PHONY:		all clean fclean re