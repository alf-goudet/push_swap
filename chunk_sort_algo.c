/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:17:00 by agoudet-          #+#    #+#             */
/*   Updated: 2026/06/23 16:41:20 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

static bool is_in_range(t_stack *a, int index_limit[2])
{
	int 		curr_index;
	int const	min = 0;
	int const	max = 1;

	curr_index = 0;
	while (curr_index <= a->bottom)
	{
		if (a->numbers[curr_index] >= index_limit[min]
			&& a->numbers[curr_index] <= index_limit[max])
			return (true);
		curr_index++;
	}
	return (false);
}

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

static void	smart_rotate_to_top(t_stack *a, int hold[2])
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

void	sort_in_chunks(t_stack *a, t_stack *b, int chk_n, int const chunk_size)
{
	int	current_chunk;
	int	index_limit[2];
	int	hold[2];

	current_chunk = 0;
	while (current_chunk < chk_n)
	{
		index_limit[0] = current_chunk * chunk_size;
		index_limit[1] = (current_chunk + 1) * chunk_size - 1;
		while (is_in_range(a, index_limit))
		{
			// 1. Find hold_first and hold_second positions here
			hold[0] = find_hold(a, index_limit, 'f');
			hold[1] = find_hold(a, index_limit, 's');
			// 2. Calculate costs and rotate the cheaper one to the top
			smart_rotate_to_top(a, hold);
			// 3. Position Stack B correctly and push (pb)
			prepare_stack_b(b, a->numbers[0]);
			pb(a, b);	
		}
		current_chunk++;
	}
}
