/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 09:54:09 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/02 12:02:02 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_three(t_stack **stack)
{
	t_stack	*maxim;

	maxim = find_maxim(*stack);
	if (*stack == maxim)
	{
		ra(stack);
	}
	else if ((*stack)->next == maxim)
	{
		rra(stack);
	}
	if ((*stack)->number > (*stack)->next->number)
	{
		sa(stack);
	}
}

static int	sorted(t_stack **stack)
{
	t_stack	*current;
	int		flag;

	current = *stack;
	flag = 1;
	while (current->next)
	{
		if (current->number > current->next->number)
		{
			flag = 0;
			break ;
		}
		current = current->next;
	}
	if (ft_stack_size(*stack) == 2 && flag == 0)
	{
		sa(stack);
		return (TRUE);
	}
	else if (ft_stack_size(*stack) == 3 && flag == 0)
	{
		sort_three(stack);
		return (TRUE);
	}
	return (flag);
}

static void	rotate_until_top(t_stack **a, t_stack **b, t_stack *ta, t_stack *tb)
{
	while (*a != ta)
	{
		if (ta->half == ABOVE)
		{
			ra(a);
		}
		else
		{
			rra(a);
		}
	}
	while (*b != tb)
	{
		if (tb->half == ABOVE)
		{
			rb(b);
		}
		else
		{
			rrb(b);
		}
	}
}

static void	moving(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	cheap = get_cheap(*b);
	if (cheap->half == ABOVE && cheap->target->half == ABOVE)
	{
		rotate_both(a, b, cheap);
	}
	else if (cheap->half == BELOW && cheap->target->half == BELOW)
	{
		reverse_rotate_both(a, b, cheap);
	}
	rotate_until_top(a, b, cheap->target, cheap);
	pa(a, b);
}

void	push_swap(t_stack **a, t_stack **b)
{
	int		len;
	t_stack	*small;

	if (sorted(a))
		return ;
	len = ft_stack_size(*a);
	while (len-- > 3)
	{
		pb(a, b);
	}
	sort_three(a);
	while (*b)
	{
		set_values(a, b);
		moving(a, b);
	}
	set_pos(*a);
	small = find_small(*a);
	if (small->half == ABOVE)
		while (*a != small)
			ra(a);
	else
		while (*a != small)
			rra(a);
}
