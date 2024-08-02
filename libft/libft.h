/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonolive <gonolive@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:44:11 by gonolive          #+#    #+#             */
/*   Updated: 2024/08/01 18:55:55 by gonolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>
#include "printf/ft_printf.h"

long	ft_atol(const char *str);
int		ft_isdigit(int n);
char	**ft_split(char const *str, char c);


#endif