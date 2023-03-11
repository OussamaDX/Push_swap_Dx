/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils_v2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:00:46 by ooussaad          #+#    #+#             */
/*   Updated: 2023/03/10 18:47:59 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_range(int *arr, int start, int end, int content)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (i < end - start + 1)
	{
		if (content == arr[start + i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write (1, str + i, 1);
		i++;
	}
}

t_stack	*last_elem(t_stack *stack)
{
	while (stack && stack->next != NULL)
	{
		stack = stack->next;
	}
	return (stack);
}

t_stack	*before_last(t_stack *stack)
{
	while (stack && stack->next && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}
