/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooussaad <ooussaad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 02:58:40 by ooussaad          #+#    #+#             */
/*   Updated: 2023/03/10 21:00:51 by ooussaad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				index;
	int				data;
	struct s_stack	*next;
}				t_stack;

typedef struct v_var
{
	int	div;
	int	middle;
	int	offset;
	int	len;
	int	start;
	int	end;
	int	down;
	int	i;
}		t_st;

t_stack	*last_elem(t_stack *stack);
t_stack	*before_last(t_stack *stack);

//checking input
int		check_dup(char **av);

//utils functions
void	ft_putstr(char *str);
void	exit_error(void);
t_stack	*new_element(int value, t_stack *next);
void	create_new_element(char *a, t_stack **lst);
int		t_strlen(char **str);
void	check_duplicate(t_stack *lst);
int		get_top(t_stack *stack);
int		lst_size(t_stack **stacka);
int		min_data(t_stack **a, int *count);
int		ft_range(int *arr, int start, int end, int content);
int		last_node(t_stack *stacka);
int		check_max_partie(t_stack **stackb, int value, int size);
void	the_if(t_stack **stackb, int *arr, int i);
int		max_data(t_stack **stack_b, int max);
void	check_overflow(char **av);
int		check_sort(t_stack **stacka, int size);
void	free_stack(t_stack **a);
//check input
void	parse(t_stack **stack, char **argv, int argc);

//rules
void	do_sa(t_stack **stack_a, int fd);
void	do_sb(t_stack **stack_a, int fd);
void	do_ss(t_stack **stack_a, t_stack **stack_b, int fd);
void	do_rra(t_stack **stack_a, int fd);
void	do_rrr(t_stack **stack_a, t_stack **stack_b, int fd);
void	do_rrb(t_stack **stack_b, int fd);
void	do_ra(t_stack **stack_a, int fd);
void	do_rb(t_stack **stack_b, int fd);
void	do_rr(t_stack **stack_a, t_stack **stack_b, int fd);
void	do_pb(t_stack **stack_a, t_stack **stack_b, int fd);
void	do_pa(t_stack **stack_a, t_stack **stack_b, int fd);

//sorts algo
void	sort_2(t_stack **stacka);
void	sort_3(t_stack **stack_a);
void	sort_numbers(t_stack **a, t_stack **b);

//large sort finctions
void	large_sort(t_stack **stack_a, t_stack **stack_b, int *arr, int size);
void	to_array(t_stack **stack_a, t_stack **stack_b);
void	bubble_sort(int *arr, int size);
void	to_be(int *arr, t_st *tmp, t_stack **stack_a, t_stack **stack_b);
void	sortfinaltoa(t_stack **stack_a, t_stack **stack_b, int *arr, t_st *va);
#endif
