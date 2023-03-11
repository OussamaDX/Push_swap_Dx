/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 03:43:31 by ooussaad          #+#    #+#             */
/*   Updated: 2023/03/07 11:53:25 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_be(int *arr, t_st *tmp, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_range(arr, tmp->start, tmp->end, (*stack_a)->data) == 1)
	{
		do_pb(stack_b, stack_a, 1);
		if ((*stack_b)->next && (*stack_b)->data < arr[tmp->middle])
			do_rb(stack_b, 1);
		else if ((*stack_b)->next && (*stack_b)->data < (*stack_b)->next->data)
			do_sb(stack_b, 1);
	}
	else
		do_ra(stack_a, 1);
	if (lst_size(stack_b) == tmp->end - tmp->start + 1)
	{
		tmp->start = tmp->start - tmp->offset;
		tmp->end = tmp->end + tmp->offset;
		if (tmp->start <= 0)
			tmp->start = 0;
		if (tmp->end >= tmp->len)
			tmp->end = tmp->len;
	}
}

void	bubble_sort(int *arr, int size)
{
	int	i;
	int	temp;
	int	j;

	if (!arr)
		return ;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	large_sort(t_stack **stack_a, t_stack **stack_b, int *arr, int size)
{
	t_st	va;

	if (!stack_a || !stack_b || !arr)
		return ;
	va.div = 10;
	va.middle = (size / 2) - 1;
	va.offset = size / va.div;
	va.len = lst_size(stack_a);
	va.start = va.middle - va.offset;
	va.end = va.middle + va.offset;
	while (*stack_a)
	{
		to_be(arr, &va, stack_a, stack_b);
	}
	va.i = lst_size(stack_b) - 1;
	va.down = 0;
	sortfinaltoa(stack_a, stack_b, arr, &va);
	free(arr);
}

void	to_array(t_stack **stack_a, t_stack **stack_b)
{
	int		j;
	int		i;
	int		*arr;
	t_stack	*temp;

	arr = malloc(lst_size(stack_a) * sizeof(int));
	i = lst_size(stack_a);
	if (!stack_a)
		return ;
	j = 0;
	temp = *stack_a;
	while (temp)
	{
		arr[j] = temp->data;
		temp = temp->next;
		j++;
	}
	bubble_sort(arr, i);
	large_sort(stack_a, stack_b, arr, i);
}
