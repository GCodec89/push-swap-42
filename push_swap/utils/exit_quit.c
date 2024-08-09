/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_quit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/02 11:58:49 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/02 11:59:24 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	exit_quit(t_stack **a, int argc, char *argv[], int error)
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
	exit(0);
}
