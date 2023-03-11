/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 03:20:30 by ooussaad          #+#    #+#             */
/*   Updated: 2023/03/07 11:54:20 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_pa(t_stack **stackb, t_stack **stacka, int fd)
{
	t_stack	*temp;

	if (*stackb == NULL)
		return ;
	temp = *stackb;
	*stackb = (*stackb)->next;
	temp->next = *stacka;
	*stacka = temp;
	if (fd == 1)
		write(1, "pa\n", 3);
}

void	do_pb(t_stack **stackb, t_stack **stacka, int fd)
{
	t_stack	*temp;

	if (*stacka == NULL)
		return ;
	temp = *stacka;
	*stacka = (*stacka)->next;
	temp->next = *stackb;
	*stackb = temp;
	if (fd == 1)
		write(1, "pb\n", 3);
}
