# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 14:13:32 by gonolive          #+#    #+#              #
#    Updated: 2024/08/06 17:01:32 by gonolive         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= push_swap

CC				= gcc
RM				= rm -rf
CFLAGS			= -Wall -Wextra -Werror -g -Iheaders/

LIBFT 			= libft/libft.a

SRCS 			= main.c \
						utils/errors.c utils/exit_quit.c utils/find.c utils/freeza.c utils/get_cheap.c utils/stacks.c \
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

download:
				@wget https://cdn.intra.42.fr/document/document/25705/checker_linux && chmod 777 checker_linux

visualizer:
				git clone https://github.com/o-reo/push_swap_visualizer.git && \
				cd push_swap_visualizer && \
				mkdir build && \
				cd build && \
				cmake .. && \
				make && \
				./bin/visualizer

re:             fclean all

.PHONY:         all clean fclean re