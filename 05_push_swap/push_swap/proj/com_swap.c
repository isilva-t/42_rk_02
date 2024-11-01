/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:24:03 by isilva-t          #+#    #+#             */
/*   Updated: 2024/06/25 12:28:24 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	swap(t_list **stack)
{
	t_list	*node_to_first;
	t_list	*node_to_second;
	t_list	*third_node;

	node_to_first = NULL;
	node_to_second = NULL;
	third_node = NULL;
	if (!*stack)
		return (0);
	if (!(*stack)->next)
		return (0);
	node_to_first = (*stack)->next;
	node_to_second = *stack;
	if ((*stack)->next->next)
	{
		third_node = (*stack)->next->next;
		third_node->prev = node_to_second;
	}
	node_to_second->prev = node_to_first;
	node_to_second->next = third_node;
	node_to_first->next = node_to_second;
	node_to_first->prev = NULL;
	*stack = node_to_first;
	return (1);
}

void	sa(t_list **stack)
{
	if (!*stack)
		return (print_err("____NO swap_a___NO begin\n"));
	if (!(*stack)->next)
		return (print_err("____NO swap_a___NO lst->next\n"));
	else if (swap(stack))
		ft_printf("sa\n");
	else
		print_err("____NO swap_b\n");
}

void	sb(t_list **stack)
{
	if (!*stack)
		return (print_err("____NO swap_b____NO begin\n"));
	if (!(*stack)->next)
		return (print_err("____NO swap_b____NO lst->next\n"));
	else if (swap(stack))
		ft_printf("sb\n");
	else
		print_err("____NO swap_b\n");
}

void	ss(t_list **a, t_list **b)
{
	if (!*a || !*b)
		return (print_err("____NO swap_both____NO begin\n"));
	if (!(*a)->next || !(*b)->next)
		return (print_err("____NO swap_both____NO lst->next\n"));
	else if (swap(a) && swap(b))
		ft_printf("ss\n");
	else
		print_err("____NO swap_both____WHAT?!?!?\n");
}
