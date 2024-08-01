/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:52:31 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/01 21:54:56 by gonolive         ###   ########.fr       */
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
