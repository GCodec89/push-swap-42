/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:23:13 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/02 12:13:31 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ft_stack_last(t_stack *stack)
{
	t_stack	*last;

	if (!stack)
	{
		return (NULL);
	}
	last = stack;
	while (last->next != NULL)
	{
		last = last->next;
	}
	return (last);
}

void	ft_stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (stack && new)
	{
		if (*stack)
		{
			last = ft_stack_last(*stack);
			last->next = new;
			new->prev = last;
		}
		else
		{
			*stack = new;
		}
	}
}

t_stack	*ft_new_node(int n)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		return (NULL);
	}
	stack->number = n;
	stack->next = NULL;
	stack->prev = NULL;
	return (stack);
}

int	ft_stack_size(t_stack *stack)
{
	t_stack	*node;
	int		i;

	i = 0;
	node = stack;
	while (node)
	{
		node = node->next;
		i++;
	}
	return (i);
}
