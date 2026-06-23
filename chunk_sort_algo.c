/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:17:00 by agoudet-          #+#    #+#             */
/*   Updated: 2026/06/23 12:03:10 by agoudet-         ###   ########.fr       */
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

static int	find_hold_first(t_stack *a, int index_limit[2])
{
	int const	min = 0;
	int const	max = 1;
	int			i;

	i = 0;
	while (i <= a->bottom)
	{
		if (a->numbers[i] >= index_limit[min]
			&& a->numbers[i] <= index_limit[max])
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

static int	find_hold_second(t_stack *a, int index_limit[2])
{
	int const	min = 0;
	int const	max = 1;
	int			i;

	i = a->bottom;
	while (i >= 0)
	{
		if (a->numbers[i] >= index_limit[min]
			&& a->numbers[i] <= index_limit[max])
		{
			return (i);
		}
		i--;
	}
	return (-1);
}

void	sort_in_chunks(t_stack *a, t_stack *b, int chk_n, int const chunk_size)
{
	int	current_chunk;
	int	index_limit[2];
	int	hold_first;
	int	hold_second;

	current_chunk = 0;
	while (current_chunk < chk_n)
	{
		index_limit[0] = current_chunk * chunk_size;
		index_limit[1] = (current_chunk + 1) * chunk_size - 1;
		while (is_in_range(a, index_limit))
		{
			// 1. Find hold_first and hold_second positions here
			hold_first = find_hold_first(a, index_limit);
			hold_second = find_hold_second(a, index_limit);
			// 2. Calculate costs and rotate the cheaper one to the top
			// 3. Position Stack B correctly and push (pb)	
		}
		current_chunk++;
	}
}
