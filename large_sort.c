/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 18:37:38 by agoudet-          #+#    #+#             */
/*   Updated: 2026/06/23 19:19:11 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	idx_replace(int *tmp_srt, t_stack *a, int n);

static int	*ft_memdup_int(const int *orig, size_t n);

void	sort_large_nbrs(t_stack *a, t_stack *b, int chk_n, int const chk_size)
{
	int		*temp_sorted_arr;
	size_t	nbr_count;

	nbr_count = a->bottom + 1;
	temp_sorted_arr = ft_memdup_int(a->numbers, nbr_count);
	quick_sort(temp_sorted_arr, top, a->bottom);
	idx_replace(temp_sorted_arr, a, nbr_count);
	free(temp_sorted_arr);
	sort_in_chunks(a, b, chk_n, chk_size);
}

static void	idx_replace(int *tmp_srt, t_stack *a, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			if (tmp_srt[j] == a->numbers[i])
			{
				a->numbers[i] = (int)j;
				break ;
			}
			j++;
		}
		i++;
	}
}

static int	*ft_memdup_int(const int *orig, size_t n)
{
	int	*dest;

	dest = (int *)malloc(n * sizeof(int));
	if (dest == NULL)
		// handle malloc error here
	ft_memcpy(dest, orig, n * sizeof(int));
	return (dest);
}
