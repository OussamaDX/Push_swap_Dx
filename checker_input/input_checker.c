/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:26:37 by ooussaad          #+#    #+#             */
/*   Updated: 2023/03/10 18:32:21 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_overflow(char **av)
{
	long long	temp;

	if (!av)
		return ;
	while (*av)
	{
		temp = ft_atoi_max(*av);
		if (temp < INT_MIN || temp > INT_MAX)
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		av++;
	}
	return ;
}
