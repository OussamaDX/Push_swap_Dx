/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 03:01:24 by ooussaad          #+#    #+#             */
/*   Updated: 2023/03/10 20:58:29 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (stack == NULL || stack->next == NULL)
		return ;
	temp = stack->data;
	stack->data = stack->next->data;
	stack->next->data = temp;
	temp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = temp;
}

void	do_sa(t_stack **stack_a, int fd)
{
	if (lst_size(stack_a) > 1)
	{
		swap(*stack_a);
		if (fd == 1)
			ft_putstr("sa\n");
	}
}

void	do_sb(t_stack **stack_b, int fd)
{
	if (lst_size(stack_b) > 1)
	{
		swap(*stack_b);
		if (fd == 1)
			ft_putstr("sb\n");
	}
}

void	do_ss(t_stack **stack_a, t_stack **stack_b, int fd)
{
	if (lst_size(stack_a) > 1 && lst_size(stack_b) > 1)
	{
		swap(*stack_a);
		swap(*stack_b);
		if (fd == 1)
			ft_putstr("ss\n");
	}
}
