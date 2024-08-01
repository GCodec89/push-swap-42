/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeza.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 09:04:51 by gonolive          #+#    #+#             */
/*   Updated: 2024/07/30 09:10:05 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!stack || !*stack)
	{
		return ;
	}
	current = *stack;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}

void	free_argv(char *argv[])
{
	int	i;

	i = -1;
	if (!argv)
	{
		return ;
	}
	while (argv[++i])
	{
		free(argv[i]);
	}
	free(argv);
}
