# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 14:13:32 by gonolive          #+#    #+#              #
#    Updated: 2024/08/02 11:59:48 by gonolive         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= push_swap

CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -g -Iheaders/

LIBFT 			= libft/libft.a

SRCS 			= main.c \
						utils/errors.c utils/exit_quit.c utils/find.c utils/freeza.c utils/stacks.c \
						coms/push.c coms/rev_rotate.c coms/rotate.c coms/swap.c\
						algorithm/push_swap.c algorithm/set_values.c \

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