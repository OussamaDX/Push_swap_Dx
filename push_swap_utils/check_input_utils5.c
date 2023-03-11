/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils5.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:02:08 by ooussaad          #+#    #+#             */
/*   Updated: 2023/03/06 23:38:37 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
