/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 21:36:45 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/01 21:44:53 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_exit(t_stack **a, int argc, char *argv[], int error)
{
	free_stack(a);
	if (argc == 2)
	{
		free_argv(argv);
	}
	if (error)
	{
		ft_printf("Error\n");
	}
	exit (0);
}
