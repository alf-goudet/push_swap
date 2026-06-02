/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 22:48:29 by agoudet-          #+#    #+#             */
/*   Updated: 2026/05/28 21:35:21 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int const	top = 0;
	int			a_count;
	int			b_count;

	b_count = b->bottom + 1;
	if (b_count == 0)
		return ;
	a_count = a->bottom + 1;
	if (a_count > 0)
	{
		ft_memmove(a->numbers + 1, a->numbers, a_count * sizeof(int));
	}
	a->bottom++;
	a->numbers[top] = b->numbers[top];
	ft_memmove(b->numbers, b->numbers + 1, (b_count - 1) * sizeof(int));
	b->numbers[b->bottom] = 0;
	b->bottom--;
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	int const	top = 0;
	int			a_count;
	int			b_count;

	a_count = a->bottom + 1;
	if (a_count == 0)
		return ;
	b_count = b->bottom + 1;
	if (b_count > 0)
	{
		ft_memmove(b->numbers + 1, b->numbers, b_count * sizeof(int));
	}
	b->bottom++;
	b->numbers[top] = a->numbers[top];
	ft_memmove(a->numbers, a->numbers + 1, (a_count - 1) * sizeof(int));
	a->numbers[a->bottom] = 0;
	a->bottom--;
	ft_printf("pb\n");
}
