/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:52:27 by isilva-t          #+#    #+#             */
/*   Updated: 2024/07/06 10:10:04 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	order_stack(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
		sa(a);
	else if (ft_lstsize(*a) == 3)
		order_three(a, 'y');
	else if (ft_lstsize(*a) == 4 || ft_lstsize(*a) == 5)
		order_four_or_five(a, b);
	else
		order_radix(a, b, NULL, 32);
	free_stack(a);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		n_words;
	int		have_error;

	a = NULL;
	b = NULL;
	have_error = 0;
	if (ac < 2 || (ac == 2 && !av[1][0]))
		return (1);
	if (ac == 2)
	{
		n_words = count_words(av[1], ' ');
		av = ft_split(av[1], ' ', n_words);
		have_error = init_stack_a(&a, av, 0, 0);
		free_mem(n_words, av);
	}
	else if (ac > 2)
		have_error = init_stack_a(&a, av + 1, 0, 0);
	if (have_error == 0 && is_not_sorted(a))
		order_stack(&a, &b);
	else
		free_stack(&a);
	return (0);
}
