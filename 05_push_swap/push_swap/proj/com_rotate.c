/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 09:45:24 by isilva-t          #+#    #+#             */
/*   Updated: 2024/07/02 10:40:29 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	rotate(t_list **stack)
{
	t_list	*new_bottom;
	t_list	*last_node;

	if (!*stack)
		return (0);
	if (!(*stack)->next)
		return (0);
	last_node = ft_lstlast(*stack);
	new_bottom = *stack;
	last_node->next = new_bottom;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	new_bottom->prev = last_node;
	new_bottom->next = NULL;
	return (1);
}

void	ra(t_list **stack)
{
	if (!*stack)
		return (print_err("______NO rotate___a____No beg-list\n"));
	if (!(*stack)->next)
		return (print_err("______NO rotate___a____No list->next\n"));
	else if (rotate(stack))
		ft_printf("ra\n");
	else
		print_err("______NO rotate___a\n");
}

void	rb(t_list **stack)
{
	if (!*stack)
		return (print_err("______NO rotate___b____No beg-list\n"));
	if (!(*stack)->next)
		return (print_err("______NO rotate___b____No list->next\n"));
	else if (rotate(stack))
		ft_printf("rb\n");
	else
		print_err("______NO rotate___b\n");
}

void	rr(t_list **a, t_list **b)
{
	if (!*a || !*b)
		return (print_err("______NO rotate_both____No beg-list\n"));
	if (!(*a)->next || !(*b)->next)
		return (print_err("______NO rotate_both_____No lst->next\n"));
	else if (rotate(a) && rotate(b))
		ft_printf("rr\n");
	else
		return (print_err("______NO rotate_both____WHAT?!?\n"));
}
