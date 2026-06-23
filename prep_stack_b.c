/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 16:35:01 by agoudet-          #+#    #+#             */
/*   Updated: 2026/06/23 17:49:04 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max(t_stack *b);

static int	find_min(t_stack *b);

static int	find_largest_smaller(t_stack *b, int incoming_nbr);

static void	smart_rotation_to_top(t_stack *b, int target_index)
{
	int	top_down_cost;
	int	bottom_up_cost;
	int	i;

	top_down_cost = target_index;
	bottom_up_cost = (b->bottom + 1) - target_index;
	i = 0;
	if (top_down_cost <= bottom_up_cost)
	{
		while (i < top_down_cost)
		{
			rb(b);
			i++;
		}
	}
	else
	{
		while (i < bottom_up_cost)
		{
			rrb(b);
			i++;
		}
	}
}

void	prepare_stack_b(t_stack *b, int incoming_nbr)
{
	int	b_max;
	int	b_min;
	int	target_index;

	if (b->bottom <= 0)
		return ;
	b_max = find_max(b);
	b_min = find_min(b);
	if (incoming_nbr > b_max || incoming_nbr < b_min)
		target_index = b_max;
	else
		target_index = find_largest_smaller(b, incoming_nbr);
	smart_rotation_to_top(b, target_index);
}

static int	find_largest_smaller(t_stack *b, int incoming_nbr)
{
	int	largest_smaller;
	int	largest_smaller_i;
	int	i;

	largest_smaller = b->numbers[0];
	largest_smaller_i = 0;
	i = 1;
	while (i <= b->bottom)
	{
		if (b->numbers[i] > largest_smaller && b->numbers[i] < incoming_nbr)
		{
			largest_smaller = b->numbers[i]
			largest_smaller_i = i;
		}
		i++;
	}
	return (largest_smaller_i);
}

static int	find_max(t_stack *b)
{
	int	max_i;
	int	max;
	int	i;

	max = b->numbers[0];
	max_i = 0;
	i = 1;
	while (i <= b->bottom)
	{
		if (b->numbers[i] > max)
		{
			max = b->numbers[i];
			max_i = i;
		}
		i++;
	}
	return (max_i);
}

static int	find_min(t_stack *b)
{
	int	min;
	int	min_i;
	int	i;

	min = b->numbers[0];
	min_i = 0;
	i = 1;
	while (i <= b->bottom)
	{
		if (b->numbers[i] < min)
		{
			min = b->numbers[i];
			min_i = i;
		}
		i++;
	}
	return (min_i);
}
