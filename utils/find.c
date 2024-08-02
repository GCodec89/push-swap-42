/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 09:22:08 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/02 09:25:01 by gonolive         ###   ########.fr       */
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
