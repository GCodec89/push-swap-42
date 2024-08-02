/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 10:12:25 by gonolive          #+#    #+#             */
/*   Updated: 2024/07/31 19:20:08 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*find_maxim(t_stack *stack)
{
	int		maxim;
	t_stack	*max_node;

	maxim = INT_MIN;
	while (stack)
	{
		if (stack->number > maxim)
		{
			maxim = stack->number;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_stack	*find_small(t_stack *stack)
{
	int		small;
	t_stack	*small_node;

	small = INT_MAX;
	while (stack)
	{
		if (stack->number < small)
		{
			small = stack->number;
			small_node = stack;
		}
		stack = stack->next;
	}
	return (small_node);
}

void	find_cheap(t_stack *stack)
{
	int		cheap;
	t_stack	*cheap_node;

	cheap = INT_MAX;
	while (stack)
	{
		if (stack->price < cheap)
		{
			cheap = stack->price;
			cheap_node = stack;
		}
		stack = stack->next;
	}
	cheap_node->cheapest = TRUE;
}
