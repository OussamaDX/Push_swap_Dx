/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:50:18 by ooussaad          #+#    #+#             */
/*   Updated: 2023/03/10 18:38:20 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_range(int *arr, int start, int end, int content)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (i < end - start + 1)
	{
		if (content == arr[start + i])
			return (1);
		i++;
	}
	return (0);
}
