/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 02:38:39 by ooussaad          #+#    #+#             */
/*   Updated: 2023/03/10 15:27:20 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*size;
	t_stack	*before_bottom;

	size = last_elem(*stack);
	before_bottom = before_last(*stack);
	tmp = *stack;
	*stack = size;
	(*stack)->next = tmp;
	before_bottom->next = NULL;
}

void	do_rra(t_stack **stack_a, int fd)
{
	if (lst_size(stack_a) > 1)
	{
		rev_rotate(stack_a);
		if (fd == 1)
			ft_putstr("rra\n");
	}
}

void	do_rrb(t_stack **stack_b, int fd)
{
	if (lst_size(stack_b) > 1)
	{
		rev_rotate(stack_b);
		if (fd == 1)
			ft_putstr("rrb\n");
	}
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b, int fd)
{
	if (lst_size(stack_a) > 1 && lst_size(stack_b) > 1)
	{
		rev_rotate(stack_a);
		rev_rotate(stack_b);
		if (fd == 1)
			ft_putstr("rrr\n");
	}
}
