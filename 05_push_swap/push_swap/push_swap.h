/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isilva-t <isilva-t@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:54:49 by isilva-t          #+#    #+#             */
/*   Updated: 2024/07/06 10:37:39 by isilva-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "./utils/ft_printf/ft_printf.h"

typedef struct s_list
{
	int				nbr;
	long			nbr_to_index;
	char			arraybit[33];
	int				index;
	int				index_a;
	int				last_wanted;
	int				above_median;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

// proj folder ##########################################

// COMMANDS_____________________________________________
// com_push
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
// com_rev_rotate
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);
// com_rotate
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
// com_swap
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **a, t_list **b);
//______________________________________________________

// free_error
void	free_stack(t_list **stack);
void	free_mem(int in_word, char **array);
void	print_err(char *str);

// order_big_stack
void	order_radix(t_list **a, t_list **b, t_list *last_wanted_a, int i);

// order_small_stack
void	order_three(t_list **stack, char do_index);
void	order_four_or_five(t_list **a, t_list **b);

// stack_index
void	ft_utoabit_stack(t_list *stack);
void	index_stack(t_list *stack);
void	make_index_again(t_list *stack);

// stack_init
int		init_stack_a(t_list **a, char	**array, int i, long n);

// stack_utils
int		is_not_sorted(t_list *stack);
t_list	*find_biggest_node(t_list *stack);
t_list	*find_lowest_node(t_list *stack);
int		how_much_bit(t_list *stack, int position, char bit);

// utils floder ###########################################

int		ft_atoi(const char *nptr);
char	**ft_split(char const *s, char c, int n_words);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
int		count_words(const char *s, char c);
int		ft_isdigit(int c);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);

// outside subject requirements, only for my testing
// uncomment to include "test" folder, and use this function (if test folder exists)
// ONLY WORKS ON "order_big_stack" to see binnary order with radix algorithm
//void	print_stack(t_list **a, t_list **b);

#endif
