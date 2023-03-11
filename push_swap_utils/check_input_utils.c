/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:49:15 by ooussaad          #+#    #+#             */
/*   Updated: 2023/03/11 13:23:02 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*new_element(int value, t_stack *next)
{
	t_stack	*lst;

	lst = malloc(sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst->data = value;
	lst->next = next;
	return (lst);
}

void	create_new_element(char *a, t_stack **lst)
{
	int	tmp;

	if (!a || !a[0])
		exit_error();
	tmp = ft_atoi(a);
	*lst = new_element(tmp, *lst);
}

int	t_strlen(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	check_duplicate(t_stack *lst)
{
	t_stack	*tmp;
	t_stack	*tmp1;
	int		count;

	tmp = lst;
	while (tmp)
	{
		count = 0;
		tmp1 = tmp;
		while (tmp1)
		{
			if (tmp1->data == tmp->data)
			{
				count++;
				if (count >= 2)
					exit_error();
			}
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}
