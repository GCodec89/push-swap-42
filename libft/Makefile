# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/01 17:29:40 by gonolive          #+#    #+#              #
#    Updated: 2024/08/01 18:00:42 by gonolive         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_SRCS	= printf/ft_printf.c printf/ft_printnbr.c printf/ft_printptr.c \
				printf/ft_printstr.c printf/ft_putchar.c printf/ft_putptrhex.c \
				ft_atol.c ft_isdigit.c ft_split.c

LIBFT_OBJS	= $(LIBFT_SRCS:.c=.o)

CC			= cc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -fPIC

NAME 		= libft.a

all:		$(NAME)

$(NAME)		$(LIBFT_OBJS)
			ar rcs $(NAME) $(LIBFT_OBJS)

clean:		$(RM) $(LIBFT_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY: 	all clean fclean re