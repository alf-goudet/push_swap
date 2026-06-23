/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_dups.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:28:39 by agoudet-          #+#    #+#             */
/*   Updated: 2026/06/08 21:39:12 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_duplicates(int *stack, int n)
{
	int	dups_found;
	int	i;
	int	j;

	dups_found = 1;
	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (stack[i] == stack[j])
			{
				return (dups_found);
			}
			j++;
		}
		i++;
	}
	return (!dups_found);
}
