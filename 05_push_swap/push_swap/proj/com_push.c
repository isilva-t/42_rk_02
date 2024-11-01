/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   com_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:05:14 by isilva-t          #+#    #+#             */
/*   Updated: 2024/06/25 12:53:40 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	push(t_list **src, t_list **dst)
{
	t_list	*node_to_push;

	if (!*src)
		return (0);
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (!*dst)
	{
		node_to_push->next = NULL;
		*dst = node_to_push;
		return (1);
	}
	else
	{
		(*dst)->prev = node_to_push;
		node_to_push->next = *dst;
		*dst = node_to_push;
		return (1);
	}
	return (0);
}

void	pa(t_list **a, t_list **b)
{
	if (push(b, a))
		ft_printf("pa\n");
	else
		print_err("__________NO push_a\n");
}

void	pb(t_list **a, t_list **b)
{
	if (push(a, b))
		ft_printf("pb\n");
	else
		print_err("__________NO push_b\n");
}
