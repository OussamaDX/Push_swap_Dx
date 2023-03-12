/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 23:26:24 by ooussaad          #+#    #+#             */
/*   Updated: 2023/03/12 16:20:07 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

void	checker(char *str, t_stack **a, t_stack **b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		do_sa(a, 0);
	else if (ft_strcmp(str, "sb\n") == 0)
		do_sb(b, 0);
	else if (ft_strcmp(str, "ss\n") == 0)
		do_ss(a, b, 0);
	else if (ft_strcmp(str, "rb\n") == 0)
		do_rb(b, 0);
	else if (ft_strcmp(str, "ra\n") == 0)
		do_ra(a, 0);
	else if (ft_strcmp(str, "rr\n") == 0)
		do_rr(a, b, 0);
	else if (ft_strcmp(str, "rra\n") == 0)
		do_rra(a, 0);
	else if (ft_strcmp(str, "rrb\n") == 0)
		do_rrb(b, 0);
	else if (ft_strcmp(str, "rrr\n") == 0)
		do_rrr(a, b, 0);
	else if (ft_strcmp(str, "pa\n") == 0)
		do_pa(b, a, 0);
	else if (ft_strcmp(str, "pb\n") == 0)
		do_pb(b, a, 0);
	else
		(write(2, "Error\n", 6), exit(0));
}

void	main_con(int size, t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_b && check_sort(stack_a, size) == 1)
		write(2, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	free_stack(stack_a);
	free_stack(stack_b);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	char		*line;
	int			size;

	if (argc < 2)
		return (0);
	parse(&stack_a, argv, argc);
	size = lst_size(&stack_a);
	if (size == 1)
	{
		exit(0);
	}
	line = get_next_line(0);
	while (line)
	{
		checker(line, &stack_a, &stack_b);
		free(line);
		line = get_next_line(0);
	}
	main_con(size, &stack_a, &stack_b);
}
