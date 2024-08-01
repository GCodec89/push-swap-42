/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 19:01:26 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/01 21:30:49 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_error(char *argv, long n, t_stack **a)
{
	int	i;
	int	res;

	res = TRUE;
	i = 0;
	if (n > INT_MAX || n < INT_MIN)
		return (FALSE);
	if ((check_repeat(*a, n)) == TRUE)
		return (FALSE);
	if ((argv[0] == '+' || argv[0] == '-') && argv[1] >= '0' && argv[1] <= '9')
	{
		i++;
		res = TRUE;
	}
	while (argv[i])
	{
		if (!(ft_isdigit(argv[i])))
		{
			return (FALSE);
		}
		i++;
	}
	return (res);
}

int	check_repeat(t_stack *a, int n)
{
	while (a)
	{
		if (a->number == n)
		{
			return (TRUE);
		}
	}
	return (FALSE);
}
