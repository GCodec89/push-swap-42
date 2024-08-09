/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cheap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 12:13:04 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/02 12:13:48 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*get_cheap(t_stack *b)
{
	while (b)
	{
		if (b->cheapest == TRUE)
		{
			return (b);
		}
		b = b->next;
	}
	return (NULL);
}
