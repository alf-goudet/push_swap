/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 20:53:28 by agoudet-          #+#    #+#             */
/*   Updated: 2026/06/26 21:53:43 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	is_in_range(t_stack *a, int index_limit[2])
{
	int			curr_index;
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
