/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 18:35:12 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/02 12:02:17 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_pos(t_stack *stack)
{
	int	i;
	int	half;

	i = 0;
	half = ft_stack_size(stack) / 2;
	while (stack)
	{
		stack->position = i;
		if (i <= half)
		{
			stack->half = ABOVE;
		}
		else
		{
			stack->half = BELOW;
		}
		stack = stack->next;
		i++;
	}
}

static void	set_target(t_stack *a, t_stack *b)
{
	int		best_value;
	t_stack	*target_node;
	t_stack	*current;

	while (b)
	{
		best_value = INT_MAX;
		current = a;
		while (current)
		{
			if (current->number > b->number && current->number < best_value)
			{
				best_value = current->number;
				target_node = current;
			}
			current = current->next;
		}
		if (best_value == INT_MAX)
			b->target = find_small(a);
		else
			b->target = target_node;
		b = b->next;
	}
}

static void	set_price(t_stack *a, t_stack *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_stack_size(a);
	len_b = ft_stack_size(b);
	while (b)
	{
		b->price = b->position;
		if (b->half == BELOW)
		{
			b->price = len_b - b->position;
		}
		if (b->target->half == ABOVE)
		{
			b->price += b->target->position;
		}
		else
		{
			b->price += len_a - b->target->position;
		}
		b = b->next;
	}
}

void	set_values(t_stack **a, t_stack **b)
{
	set_pos(*a);
	set_pos(*b);
	set_target(*a, *b);
	set_price(*a, *b);
	find_cheap(*b);
}
