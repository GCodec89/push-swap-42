/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:08:02 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/02 09:26:53 by gonolive         ###   ########.fr       */
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
		if (current->next > current->next->next)
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

void	push_swap(t_stack **a, t_stack **b)
{
	int	len;

	if (sorted(a))
	{
		return ;
	}
	len = ft_stack_size(*a);
	while (len-- > 3)
	{
		pb(a, b);
	}
	sort_three(a);
}
