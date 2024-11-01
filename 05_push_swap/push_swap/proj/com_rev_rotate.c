/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:35:07 by isilva-t          #+#    #+#             */
/*   Updated: 2024/07/02 10:40:47 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	rev_rotate(t_list **stack)
{
	t_list	*last_node;

	if (!*stack)
		return (0);
	if (!(*stack)->next)
		return (0);
	last_node = ft_lstlast(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
	return (1);
}

void	rra(t_list **a)
{
	if (rev_rotate(a))
		ft_printf("rra\n");
	else
		print_err("______NO REV_rotate___a____NO begin\n");
}

void	rrb(t_list **b)
{
	if (rev_rotate(b))
		ft_printf("rrb\n");
	else
		print_err("______NO REV_rotate___b____NO begin\n");
}

void	rrr(t_list **a, t_list **b)
{
	if (!*a || !*b)
		return (print_err("______NO REV_rotate_both____NO list\n"));
	if (!(*a)->next || !(*b)->next)
		return (print_err("______NO REV_rotate_both____NO list->next\n"));
	if (rev_rotate(a) && rev_rotate(b))
		ft_printf("rrr\n");
	else
		return (print_err("______NO REV_rotate_both____WTF?!?!?!\n"));
}
