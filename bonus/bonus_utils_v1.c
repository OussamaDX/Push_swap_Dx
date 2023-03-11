/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils_v1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:59:21 by ooussaad          #+#    #+#             */
/*   Updated: 2023/03/10 20:58:07 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	lst_size(t_stack **stacka)
{
	t_stack	*temp;
	int		i;

	if (*stacka)
	{
		temp = *stacka;
		i = 0;
		while (temp)
		{
			temp = temp->next;
			i++;
		}
		return (i);
	}
	return (0);
}

int	min_data(t_stack **a, int *count)
{
	t_stack	*tmp;
	int		min;

	min = (*a)->data;
	tmp = *a;
	while (tmp)
	{
		if (tmp->data < min)
			min = tmp->data;
		tmp = tmp->next;
	}
	tmp = *a;
	*count = 0;
	while (tmp && tmp->data != min)
	{
		(*count)++;
		tmp = tmp->next;
	}
	return (min);
}

int	max_data(t_stack **stack_b, int max)
{
	t_stack	*temp;

	if (!stack_b || !*stack_b)
		return (0);
	temp = *stack_b;
	while (temp->next != NULL && max != temp->data)
		temp = temp->next;
	if (max == temp->data)
		return (1);
	else
		return (0);
}
