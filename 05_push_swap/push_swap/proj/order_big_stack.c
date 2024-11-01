/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_big_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:31:20 by isilva-t          #+#    #+#             */
/*   Updated: 2024/07/06 11:00:00 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	bit_sequence_ok(t_list *stack, int i, char stack_name)
{
	if (!stack)
		return (1);
	while (stack && stack->next)
	{
		if (stack_name == 'a')
		{
			if (stack->arraybit[i] == '1' && stack->next->arraybit[i] == '0')
				return (0);
		}
		if (stack_name == 'b')
		{
			if (stack->arraybit[i] == '0' && stack->next->arraybit[i] == '1')
				return (0);
		}
		stack = stack->next;
	}
	return (1);
}

static t_list	*find_last_wanted(t_list *stack, int i, int bit)
{
	t_list	*last_node;

	if (!stack)
		return (NULL);
	last_node = ft_lstlast(stack);
	while (last_node)
	{
		if (last_node->arraybit[i] == bit)
			return (last_node);
		last_node = last_node->prev;
	}
	return (last_node);
}

static void	radix_b(t_list **a, t_list **b, t_list *last_wanted_b, int i)
{
	if (!a || !b || !*b)
		return ;
	if (how_much_bit(*b, i - 1, '0') == ft_lstsize(*b))
		return ;
	last_wanted_b = find_last_wanted(*b, i - 1, '0');
	while (how_much_bit(*b, i - 1, '1') > 0)
	{
		if (how_much_bit(*b, i - 1, '1') == 0
			&& ft_lstlast(*b) == last_wanted_b)
			break ;
		if (*b && (*b)->arraybit[i - 1] == '1')
			pa(a, b);
		else
			rb(b);
	}
	if ((i - 1) < 30 && ft_lstsize(*b) > 1)
		while (ft_lstlast(*b) != last_wanted_b)
			rb(b);
}

static void	move_last_wanted_a(t_list **a, t_list *last_wanted_a, int i)
{
	if (!a || !*a || !last_wanted_a)
		return ;
	if (i < 32 && ft_lstsize(*a) > 1)
	{
		while (ft_lstlast(*a) != last_wanted_a)
		{
			make_index_again(*a);
			if (last_wanted_a->above_median == 0)
				rra(a);
			if (last_wanted_a->above_median == 1)
				ra(a);
		}
	}
}

void	order_radix(t_list **a, t_list **b, t_list *last_wanted_a, int i)
{
	if (!a || !b || !*a)
		return ;
	index_stack(*a);
	ft_utoabit_stack(*a);
	while (--i >= 0)
	{
		if (how_much_bit(*a, i, '1') == ft_lstsize(*a)
			|| how_much_bit(*a, i, '0') == ft_lstsize(*a))
			continue ;
		last_wanted_a = find_last_wanted(*a, i, '1');
		while (how_much_bit(*a, i, '0') > 0)
		{
			if (bit_sequence_ok(*a, i, 'a') && ft_lstlast(*a) == last_wanted_a)
				break ;
			if (*a && (*a)->arraybit[i] == '0' && how_much_bit(*a, i, '1') > 0)
				pb(a, b);
			else
				ra(a);
		}
		move_last_wanted_a(a, last_wanted_a, i);
		radix_b(a, b, NULL, i);
	}
	while (*b)
		pa(a, b);
	free_stack(a);
}

//print_stack(a, b);
//UNCOMMENT 
