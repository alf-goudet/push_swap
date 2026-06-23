/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 17:02:58 by agoudet-          #+#    #+#             */
/*   Updated: 2026/06/19 20:09:44 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// NOTE: The number of integers currently on stack (nbr_count) is calculated as
// the index of a's bottom number (the last number in the array) plus 1.
void	sort_numbers(t_stack *a, t_stack *b)
{
	int			top_is_greater;
	int			nbr_count;
	int const	top = 0;

	top_is_greater = a->numbers[top] > a->numbers[top + 1];
	nbr_count = a->bottom + 1;
	if (nbr_count == 1)
		return ;
	else if (nbr_count == 2 && top_is_greater)
		sa(a);
	else if (nbr_count == 3)
		sort_3_numbers(a, top);
	else if (nbr_count == 5)
		sort_5_numbers(a, b, top);
	else if (nbr_count >= 100)
		sort_100_numbers(a, b, top);
	else if (nbr_count >= 500)
		sort_500_numbers(a, b, top);
}
