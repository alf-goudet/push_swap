/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 22:07:00 by agoudet-          #+#    #+#             */
/*   Updated: 2026/05/25 22:11:53 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	int const	top = 0;
	int			temp;
	int			num_count;

	num_count = a->bottom + 1;
	if (num_count < 2)
		return ;
	temp = a->numbers[a->bottom];
	ft_memmove(a->numbers + 1, a->numbers, (num_count - 1) * sizeof(int));
	a->numbers[top] = temp;
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	int const	top = 0;
	int			temp;
	int			num_count;

	num_count = b->bottom + 1;
	if (num_count < 2)
		return ;
	temp = b->numbers[b->bottom];
	ft_memmove(b->numbers + 1, b->numbers, (num_count - 1) * sizeof(int));
	b->numbers[top] = temp;
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
