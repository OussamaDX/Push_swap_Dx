/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 03:21:33 by ooussaad          #+#    #+#             */
/*   Updated: 2023/03/10 15:32:43 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*size;

	temp = *stack;
	*stack = (*stack)->next;
	size = last_elem(*stack);
	temp->next = NULL;
	size->next = temp;
}

void	do_ra(t_stack **stack_a, int fd)
{
	if (lst_size(stack_a) > 1)
	{	
		rotate(stack_a);
		if (fd == 1)
			ft_putstr("ra\n");
	}
}

void	do_rb(t_stack **stack_b, int fd)
{
	if (lst_size(stack_b) > 1)
	{	
		rotate(stack_b);
		if (fd == 1)
			ft_putstr("rb\n");
	}
}

void	do_rr(t_stack **stack_a, t_stack **stack_b, int fd)
{
	if (lst_size(stack_b) > 1 && lst_size(stack_a) > 1)
	{
		rotate(stack_a);
		rotate(stack_b);
		if (fd == 1)
			ft_putstr("rr\n");
	}
}
