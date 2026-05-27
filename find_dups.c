/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_dups.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 13:28:39 by agoudet-          #+#    #+#             */
/*   Updated: 2026/05/27 13:53:16 by agoudet-         ###   ########.fr       */
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
		j = 0;
		while (j < n)
		{
			if (stack[i] == stack[j] && i != j)
			{
				return (dups_found);
			}
			j++;
		}
		i++;
	}
	return (!dups_found);
}
