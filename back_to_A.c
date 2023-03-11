/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_to_A.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 03:49:05 by ooussaad          #+#    #+#             */
/*   Updated: 2023/03/07 11:55:23 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_max_partie(t_stack **stackb, int value, int size)
{
	int		first_part;
	int		i;
	t_stack	*temp;

	if (!stackb || !*stackb)
		return (0);
	first_part = size / 2;
	i = 0;
	temp = *stackb;
	while (*stackb && i < first_part)
	{
		if (temp->data != value)
		{
			temp = temp->next;
			i++;
		}
		else if (temp->data == value)
			return (1);
	}
	return (0);
}

void	the_if(t_stack **stackb, int *arr, int i)
{
	if (check_max_partie(stackb, arr[i], i) == 1)
		do_rb(stackb, 1);
	else if (check_max_partie(stackb, arr[i], i) == 0)
		do_rrb(stackb, 1);
}

int	tail(t_stack *stacka)
{
	if (!stacka)
		return (0);
	while (stacka->next)
		stacka = stacka->next;
	return (stacka->data);
}

void	sortfinaltoa(t_stack **stack_a, t_stack **stack_b, int *arr, t_st *va)
{
	while (*stack_b || va->i >= 0)
	{
		if (max_data(stack_b, arr[va->i]) == 1)
		{
			if ((*stack_b)->data == arr[va->i])
			{
				do_pa(stack_b, stack_a, 1);
				va->i--;
			}
			else if (va->down == 0 || (*stack_b)->data > tail(*stack_a))
			{
				do_pa(stack_b, stack_a, 1);
				do_ra(stack_a, 1);
				va->down++;
			}
			else
				the_if(stack_b, arr, va->i);
		}
		else
		{
			do_rra(stack_a, 1);
			va->i--;
			va->down--;
		}
	}
}
