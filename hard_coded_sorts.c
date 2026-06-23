/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_coded_sorts.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:52:19 by agoudet-          #+#    #+#             */
/*   Updated: 2026/06/18 18:23:06 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Overview: Various sorting algorithms coded manually: Sort 3, 4 and 5 numbers

static unsigned int	find_smallest(t_stack *a);

static void	push_smallest_to_b(t_stack *a, t_stack *b, unsigned int small_i);

// 	3-number push_swap sorting algorithm:
// 	------------------------------------
void	sort_3_numbers(t_stack *a, int const top)
{
	int const	mid = 1;
	int const	bot = 2;
	int			nbr[3];

	nbr[top] = a->numbers[top];
	nbr[mid] = a->numbers[mid];
	nbr[bot] = a->numbers[a->bottom];
	if (nbr[top] > nbr[mid] && nbr[top] < nbr[bot] && nbr[mid] < nbr[bot])
		sa(a);
	else if (nbr[top] > nbr[mid] && nbr[top] > nbr[bot] && nbr[mid] < nbr[bot])
		ra(a);
	else if (nbr[top] < nbr[mid] && nbr[top] > nbr[bot] && nbr[mid] > nbr[bot])
		rra(a);
	else if (nbr[top] > nbr[mid] && nbr[top] > nbr[bot] && nbr[mid] > nbr[bot])
	{
		ra(a);
		sa(a);
	}
	else if (nbr[top] < nbr[mid] && nbr[top] < nbr[bot] && nbr[mid] > nbr[bot])
	{
		sa(a);
		ra(a);
	}
}

// 5-number push_swap sorting algorithm:
// ------------------------------------
void	sort_5_numbers(t_stack *a, t_stack *b, int const top)
{
	unsigned int	small_i;
	int				*nbr;

	nbr = a->numbers;
	if (nbr[0] < nbr[1] && nbr[0] < nbr[2] && nbr[0] < nbr[3]
		&& nbr[0] < nbr[4] && nbr[1] < nbr[2] && nbr[1] < nbr[3]
		&& nbr[1] < nbr[4] && nbr[2] < nbr[3] && nbr[2] < nbr[4]
		&& nbr[3] < nbr[4])
		return ;
	small_i = find_smallest(a);
	push_smallest_to_b(a, b, small_i);
	small_i = find_smallest(a);
	push_smallest_to_b(a, b, small_i);
	sort_3_numbers(a, top);
	pa(a, b);
	pa(a, b);
}

static unsigned int	find_smallest(t_stack *a)
{
	int				smallest_idx;
	unsigned int	idx;
	unsigned int	len;

	len = a->bottom + 1;
	smallest_idx = 0;
	idx = 1;
	while (idx < len)
	{
		if (a->numbers[idx] < a->numbers[smallest_idx])
			smallest_idx = idx;
		idx++;
	}
	return (smallest_idx);
}

static void	push_smallest_to_b(t_stack *a, t_stack *b, unsigned int small_i)
{
	unsigned int	stack_size;

	stack_size = a->bottom + 1;
	if (small_i == 1)
		sa(a);
	else if (small_i == 2)
	{
		ra(a);
		ra(a);
	}
	else if (small_i == 3)
	{
		rra(a);
		if (stack_size == 5)
			rra(a);
	}
	else if (small_i == 4)
		rra(a);
	pb(a, b);
}
