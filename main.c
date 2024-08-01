/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:09:10 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/01 21:51:06 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack_a(char *argv[], t_stack **a, int argc)
{
	int		i;
	long	n;

	i = 0;
	while (argv[i])
	{
		n = ft_atol(argv[i]);
		if (!check_error(argv[i], n, a))
		{
			ft_exit(a, argc, argv, 1);
		}
		ft_stack_add_back(a, ft_new_node(n));
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	**args;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		return (0);
	}
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
	}
	else
	{
		args = argv + 1;
	}
	init_stack_a(args, &a, argc);
}
