/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:17:00 by agoudet-          #+#    #+#             */
/*   Updated: 2026/06/23 10:22:46 by agoudet-         ###   ########.fr       */
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
	int	hold_first;
	int	hold_second;

	current_chunk = 0;
	while (current chunk < chk_n)
	{
		min_index = current_chunk = chunk_size;
		max_index = (current_chunk + 1) * chunk_size + 1;
		if (is_in_range(a, min_index, max_index))
	}
}
