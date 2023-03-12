/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 03:24:45 by ooussaad          #+#    #+#             */
/*   Updated: 2023/03/12 15:45:17 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	k;

	k = 0;
	while (str[k])
	{
		free(str[k]);
		k++;
	}
}

void	parse(t_stack **stack, char **argv, int argc)
{
	int		index;
	int		i;
	char	**str;

	index = argc - 1;
	while (index > 0)
	{
		str = ft_split(argv[index], ' ');
		if (!str[0])
			exit_error();
		i = t_strlen(str) - 1;
		while (i >= 0)
		{
			create_new_element(str[i], stack);
			i--;
		}
		ft_free(str);
		free(str);
		i++;
		index--;
	}
	check_overflow(argv);
	check_duplicate(*stack);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			size;

	if (argc < 2)
		return (0);
	parse(&stack_a, argv, argc);
	size = lst_size(&stack_a);
	if (check_sort (&stack_a, size) == 1 || size == 1)
		exit(0);
	if (size == 2)
		sort_2(&stack_a);
	else if (size == 3)
		sort_3(&stack_a);
	else if (size <= 5)
		sort_numbers(&stack_a, &stack_b);
	else if (size >= 6 && size < 10)
		sort_numbers(&stack_a, &stack_b);
	else if (size >= 10)
		to_array(&stack_a, &stack_b);
}
