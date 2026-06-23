/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 21:10:57 by agoudet-          #+#    #+#             */
/*   Updated: 2026/06/23 19:51:56 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"	// to use my ft_printf
# include "ft_printf/libft/libft.h"	// to use my libft functions
# include <stdlib.h>				// for malloc, free, exit

// Standard structure for stacks
typedef struct s_stack
{
	int	bottom;
	int	*numbers;
}		t_stack;

// Main helper functions
int		has_duplicates(int *stack, int n);
void	sort_numbers(t_stack *a, t_stack *b);
void	handle_error(t_stack *a, t_stack *b);
void	free_stacks(t_stack *a, t_stack *b);

// Operation functions
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// Sorting algorithm functions
void	sort_3_numbers(t_stack *a, int const top);
void	sort_5_numbers(t_stack *a, t_stack *b, int const top);
void	sort_large_nbrs(t_stack *a, t_stack *b, int chk_n, int chk_size);

// Other helper functions
void	quick_sort(int *array, int start, int end);
void	sort_in_chunks(t_stack *a, t_stack *b, int chk_n, int const chunk_size);
void	prepare_stack_b(t_stack *b, int incoming_nbr);
int		find_max(t_stack *b);

#endif
