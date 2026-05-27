/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 22:48:29 by agoudet-          #+#    #+#             */
/*   Updated: 2026/05/25 21:43:13 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack *a, t_stack *b)
{
	int const	top = 0;
	int			a_count;
	int			b_count;
	int			temp;

	b_count = b->bottom + 1;
	if (b_count == 0)
		return ;
	temp = b->numbers[top];
	a_count = a->bottom + 1;
	ft_memmove(b->numbers, b->numbers + 1, b_count * sizeof(int));
	b->bottom--;
	if (a_count > 0)
		ft_memmove(a->numbers + 1, a->numbers, a_count * sizeof(int));
	a->numbers[top] = temp;
	a->bottom++;
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	int const	top = 0;
	int			a_count;
	int			b_count;
	int			temp;

	a_count = a->bottom + 1;
	if (a_count == 0)
		return ;
	temp = a->numbers[top];
	b_count = b->bottom + 1;
	ft_memmove(a->numbers, a->numbers + 1, a_count * sizeof(int));
	a->bottom--;
	if (b_count > 0)
		ft_memmove(b->numbers + 1, b->numbers, b_count * sizeof(int));
	b->numbers[top] = temp;
	b->bottom++;
	ft_printf("pb\n");
}
