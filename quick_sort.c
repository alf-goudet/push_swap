/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 16:20:56 by agoudet-          #+#    #+#             */
/*   Updated: 2026/06/21 21:39:07 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	partition(int *array, int start, int end);

static void	swap(int *first, int *second);

// Main Quick Sort logic
void	quick_sort(int *array, int start, int end)
{
	int	part_idx;

	if (start < end)
	{
		part_idx = partition(array, start, end);
		quick_sort(array, start, part_idx - 1);
		quick_sort(array, part_idx + 1, end);
	}
}

static int	partition(int *array, int start, int end)
{
	int	pivot;
	int	start_bound;
	int	idx;

	pivot = array[end];
	start_bound = start - 1;
	idx = start;
	while (idx < end)
	{
		if (array[idx] < pivot)
		{
			start_bound++;
			swap(array + start_bound, array + idx);
		}
		idx++;
	}
	swap(array + end, array + start_bound + 1);
	return (start_bound + 1);
}

static void	swap(int *first, int *second)
{
	int	temp_store;

	temp_store = *first;
	*first = *second;
	*second = temp_store;
}
