/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:35:57 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/02 12:04:11 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include "libft/libft.h"

# define TRUE 1
# define FALSE 0
# define ABOVE 2
# define BELOW 3

typedef struct s_stack
{
	int				number;
	int				position;
	int				price;
	int				half;
	int				cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	push_swap(t_stack **a, t_stack **b);
void	set_pos(t_stack *stack);
void	set_values(t_stack **a, t_stack **b);

void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheap);

void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheap);

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

int		check_error(char *argv, long n, t_stack **a);
int		check_repeat(t_stack *a, int n);

int		exit_quit(t_stack **a, int argc, char *argv[], int error);

t_stack	*find_maxim(t_stack *stack);
t_stack	*find_small(t_stack *stack);
void	find_cheap(t_stack *stack);

void	free_stack(t_stack **stack);
void	free_argv(char *argv[]);

void	ft_stack_add_back(t_stack **stack, t_stack *new);
void	*ft_stack_last(t_stack *stack);
t_stack	*ft_new_node(int n);
int		ft_stack_size(t_stack *stack);
t_stack	*get_cheap(t_stack *b);

#endif