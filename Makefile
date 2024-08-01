# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 18:05:28 by gonolive          #+#    #+#              #
#    Updated: 2024/08/01 21:52:20 by gonolive         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= push_swap

CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -g -Iheaders/

LIBFT 			= libft/libft.a

SRCS 			= main.c \
						utils/erros.c utils/exit.c utils/freeza.c utils/stacks.c \

OBJS 			= $(SRCS:%.c=%.o)

all:			$(NAME)

$(LIBFT):
				@$(MAKE) -C ./libft

$(NAME):		$(OBJS) $(LIBFT)
				@$(CC) $(OBJS) $(CFLAGS) $(LIBFT) -o $(NAME)

clean:
				@$(MAKE) clean -C ./libft
				@$(RM) $(OBJS)

fclean:         clean
				@$(MAKE) fclean -C ./libft
				@$(RM) $(NAME)

re:             fclean all

.PHONY:         all clean fclean re