/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 19:53:19 by agoudet-          #+#    #+#             */
/*   Updated: 2026/05/26 16:05:59 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int const	top = 0;
	int			temp;
	int			num_count;

	num_count = a->bottom + 1;
	if (num_count < 2)
		return ;
	temp = a->numbers[top];
	a->numbers[top] = a->numbers[top + 1];
	a->numbers[top + 1] = temp;
	ft_printf("sa\n");
}

void	sb(t_stack *b)
{
	int const	top = 0;
	int			temp;
	int			num_count;

	num_count = b->bottom + 1;
	if (num_count < 2)
		return ;
	temp = b->numbers[top];
	b->numbers[top] = b->numbers[top + 1];
	b->numbers[top + 1] = temp;
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}
