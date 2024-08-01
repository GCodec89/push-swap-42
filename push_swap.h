/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:22:22 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/01 21:55:10 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

# define TRUE 1
# define FALSE 0

typedef struct s_stack
{
	int				number;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}	t_stack;

int		check_error(char *argv, long n, t_stack **a);
int		check_repeat(t_stack *a, int n);

int		ft_exit(t_stack **a, int argc, char *argv[], int error);

void	free_stack(t_stack **stack);
void	free_argv(char *argv[]);

void	*ft_stack_last(t_stack *stack);
void	ft_stack_add_back(t_stack **stack, t_stack *new);
t_stack	*ft_new_node(int n);


#endif