/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:17:00 by agoudet-          #+#    #+#             */
/*   Updated: 2026/06/23 11:19:56 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdbool.h>

static bool is_in_range(t_stack *a, int min_index, int max_index)
{
	int curr_index;

	curr_index = 0;
	while (curr_index <= a->bottom)
	{
		if (a->numbers[curr_index] >= min_index
			&& a->numbers[curr_index] <= max_index)
			return (true);
		curr_index++;
	}
	return (false);
}

void	sort_in_chunks(t_stack *a, t_stack *b, int chk_n, int const chunk_size)
{
	int	current_chunk;
	int	min_index;
	int	max_index;

	current_chunk = 0;
	while (current_chunk < chk_n)
	{
		min_index = current_chunk * chunk_size;
		max_index = (current_chunk + 1) * chunk_size - 1;
		while (is_in_range(a, min_index, max_index))
		{
			// 1. Find hold_first and hold_second positions here
			// 2. Calculate costs and rotate the cheaper one to the top
			// 3. Position Stack B correctly and push (pb)	
		}
		current_chunk++;
	}
}
