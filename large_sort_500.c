/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort_500.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 10:57:18 by agoudet-          #+#    #+#             */
/*   Updated: 2026/06/23 11:04:35 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	idx_replace(int *tmp_srt, t_stack *a, int n);

static int	*ft_memdup_int(const int *orig, size_t n);

void	sort_500_numbers(t_stack *a, t_stack *b, int const top)
{
	int		*temp_sorted_arr;
	size_t	nbr_count;

	nbr_count = a->bottom + 1;
	temp_sorted_arr = ft_memdup_int(a->numbers, (size_t)nbr_count);
	quick_sort(temp_sorted_arr, top, a->bottom);
	idx_replace(temp_sorted_arr, a, nbr_count);
	sort_in_chunks(a, b, 11, 45);
	free(temp_sorted_arr);
}

static void	idx_replace(int *tmp_srt, t_stack *a, int n)
{
	unsigned int	copy_i;
	unsigned int	orig_i;

	copy_i = 0;
	while (copy_i < nbr_count)
	{
		orig_i = 0;
		while (1)
		{
			if (tmp_srt[copy_i] == a->numbers[orig_i])
			{
				a->numbers[orig_i] = copy_i;
				break ;
			}
			orig_i++;
		}
		copy_i++;
	}
}

static int	*ft_memdup_int(const int *orig, size_t n)
{
	int	*dest;

	dest = (int *)malloc(n * sizeof(int));
	// Handle malloc failure here
	ft_memcpy(dest, orig, n * sizeof(int));
	return (dest);
}
