/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:17:00 by agoudet-          #+#    #+#             */
/*   Updated: 2026/06/26 21:59:29 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_hold(t_stack *a, int index_limit[2], char to_find)
{
	int	i;

	if (to_find == 'f')
	{
		i = 0;
		while (i <= a->bottom)
		{
			if (a->numbers[i] >= index_limit[0]
				&& a->numbers[i] <= index_limit[1])
				return (i);
			i++;
		}
	}
	else if (to_find == 's')
	{
		i = a->bottom;
		while (i >= 0)
		{
			if (a->numbers[i] >= index_limit[0]
				&& a->numbers[i] <= index_limit[1])
				return (i);
			i--;
		}
	}
	return (-1);
}

static void	smart_rotate_a_to_top(t_stack *a, int hold[2])
{
	int	top_down_cost;
	int	bottom_up_cost;
	int	i;

	top_down_cost = hold[0];
	bottom_up_cost = (a->bottom + 1) - hold[1];
	i = 0;
	if (top_down_cost <= bottom_up_cost)
	{
		while (i < top_down_cost)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		while (i < bottom_up_cost)
		{
			rra(a);
			i++;
		}
	}
}

static void	smart_rotate_b_to_top(t_stack *b)
{
	int	max_index;
	int	top_down_cost;
	int	bottom_up_cost;
	int	i;

	max_index = find_max(b);
	top_down_cost = max_index;
	bottom_up_cost = (b->bottom + 1) - max_index;
	i = 0;
	if (top_down_cost <= bottom_up_cost)
	{
		while (i < top_down_cost)
		{
			rb(b);
			i++;
		}
	}
	else
	{
		while (i < bottom_up_cost)
		{
			rrb(b);
			i++;
		}
	}
}

static void	push_back_to_a(t_stack *a, t_stack *b)
{
	while (b->bottom >= 0)
	{
		smart_rotate_b_to_top(b);
		pa(a, b);
	}
}

void	sort_in_chunks(t_stack *a, t_stack *b, int chk_n, int const chunk_size)
{
	int	current_chunk;
	int	index_limit[2];
	int	hold[2];
	int	total_elements;

	total_elements = a->bottom + 1;
	current_chunk = 0;
	while (current_chunk < chk_n)
	{
		index_limit[0] = current_chunk * chunk_size;
		index_limit[1] = (current_chunk + 1) * chunk_size - 1;
		if (current_chunk == chk_n - 1)
			index_limit[1] = total_elements - 1;
		while (is_in_range(a, index_limit))
		{
			hold[0] = find_hold(a, index_limit, 'f');
			hold[1] = find_hold(a, index_limit, 's');
			smart_rotate_a_to_top(a, hold);
			prepare_stack_b(b, a->numbers[0]);
			pb(a, b);
		}
		current_chunk++;
	}
	push_back_to_a(a, b);
}
