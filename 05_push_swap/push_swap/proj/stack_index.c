/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 09:48:57 by isilva-t          #+#    #+#             */
/*   Updated: 2024/07/06 09:49:04 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_utoabit_stack(t_list *stack)
{
	long	i;
	long	rest;
	long	nbr;

	if (!stack)
		return ;
	while (stack)
	{
		nbr = stack->index_a;
		i = 0;
		while (i < 32)
			stack->arraybit[i++] = '0';
		while (--i >= 0 && nbr != 0)
		{
			rest = nbr;
			nbr = nbr / 2;
			stack->arraybit[i] = rest % 2 + '0';
		}
		stack->arraybit[32] = 0;
		stack = stack->next;
	}
}

void	index_stack(t_list *stack)
{
	unsigned int	i;
	t_list			*lowest_node;

	i = 0;
	if (!stack && !stack->nbr_to_index)
		return ;
	lowest_node = find_lowest_node(stack);
	while (lowest_node->nbr_to_index != (long)2147483647 + 1)
	{
		lowest_node->index_a = i++;
		lowest_node->nbr_to_index = (long)2147483647 + 1;
		lowest_node = find_lowest_node(stack);
	}
}

void	make_index_again(t_list *stack)
{
	int	index;
	int	lstsize;

	index = 0;
	if (!stack)
		return ;
	lstsize = ft_lstsize(stack);
	while (stack)
	{
		stack->index = index++;
		if (stack->index < lstsize / 2)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
	}
}
