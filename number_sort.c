/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/01 17:02:58 by agoudet-          #+#    #+#             */
/*   Updated: 2026/06/02 21:42:24 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3_numbers(t_stack *a, int const top);

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
	else if (nbr_count >= 3 && nbr_count < 5)
		sort_3_numbers(a, top);
}

static void	sort_3_numbers(t_stack *a, int const top)
{
	int	const	mid = 1;
	int			top_mid_comp;
	int			top_bot_comp;
	int			mid_bot_comp;

	top_mid_comp = ft_memcmp(a->numbers[top], a->numbers[mid], sizeof(int));
}
