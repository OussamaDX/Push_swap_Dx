/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:44:38 by ooussaad          #+#    #+#             */
/*   Updated: 2023/03/07 11:44:15 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **stacka)
{
	if ((*stacka)->data > (*stacka)->next->data)
		do_sa(stacka, 1);
}

void	sort_3(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->data;
	b = (*stack_a)->next->data;
	c = (*stack_a)->next->next->data;
	if (a > b && b < c && a < c)
		do_sa(stack_a, 1);
	else if (a > b && c < a && b > c)
	{
		do_sa(stack_a, 1);
		do_rra(stack_a, 1);
	}
	else if (a > c && a > b && c > b)
		do_ra(stack_a, 1);
	else if (a < c && a < b && b > c)
	{
		do_sa(stack_a, 1);
		do_ra(stack_a, 1);
	}
	else if (a < b && c < a)
		do_rra(stack_a, 1);
}

void	sort_numbers(t_stack **a, t_stack **b)
{
	int	i;
	int	min;

	i = 0;
	while (lst_size(a) > 3)
	{
		min = min_data(a, &i);
		while ((*a)->data != min && i <= lst_size(a) / 2)
			do_ra(a, 1);
		while ((*a)->data != min && i > lst_size(a) / 2)
			do_rra(a, 1);
		do_pb(b, a, 1);
	}
	sort_3(a);
	while (*b)
		do_pa(b, a, 1);
}
