/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 16:45:19 by agoudet-          #+#    #+#             */
/*   Updated: 2026/05/25 22:11:45 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	int const	top = 0;
	int			temp;
	int			num_count;

	num_count = a->bottom + 1;
	if (num_count < 2)
		return ;
	temp = a->numbers[top];
	ft_memmove(a->numbers, a->numbers + 1, (num_count - 1) * sizeof(int));
	a->numbers[a->bottom] = temp;
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	int const	top = 0;
	int			temp;
	int			num_count;

	num_count = b->bottom + 1;
	if (num_count < 2)
		return ;
	temp = b->numbers[top];
	ft_memmove(b->numbers, b->numbers + 1, (num_count - 1) * sizeof(int));
	b->numbers[b->bottom] = temp;
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
