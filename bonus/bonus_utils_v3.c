/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils_v3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:01:43 by ooussaad          #+#    #+#             */
/*   Updated: 2023/03/07 15:34:06 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_top(t_stack *stack)
{
	if (!stack)
		return (0);
	return (stack->data);
}

int	last_node(t_stack *stacka)
{
	if (!stacka)
		return (0);
	while (stacka->next)
		stacka = stacka->next;
	return (stacka->data);
}

int	check_sort(t_stack **stacka, int size)
{
	t_stack	*tmp;

	if (!*stacka)
		return (0);
	tmp = *stacka;
	if (size < 2)
		exit(1);
	while (tmp && tmp->next)
	{
		if (tmp->data < tmp->next->data)
			tmp = tmp->next;
		else
		{
			return (0);
		}
	}
	return (1);
}

void	free_stack(t_stack **a)
{
	t_stack	*tmp;

	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}
