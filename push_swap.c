/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 20:12:31 by agoudet-          #+#    #+#             */
/*   Updated: 2026/06/23 19:51:56 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initialise_stacks(t_stack *a, t_stack *b, int argc, char **argv);

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		exit(EXIT_FAILURE);
	initialise_stacks(&a, &b, argc, argv);
	sort_numbers(&a, &b);
	free_stacks(&a, &b);
	exit(EXIT_SUCCESS);
}

// NOTE on initialise_stacks():
// ---------------------------
// For each stack, bottom index -1 means the stack is empty, because of
// the zero-based index notation of C arrays.
static void	initialise_stacks(t_stack *a, t_stack *b, int argc, char **argv)
{
	int	idx;
	int	nbr;

	a->numbers = (int *)ft_calloc(argc - 1, sizeof(int));
	b->numbers = (int *)ft_calloc(argc - 1, sizeof(int));
	if (a->numbers == NULL || b->numbers == NULL)
		handle_error(a, b);
	a->bottom = -1;
	b->bottom = -1;
	idx = argc - 1;
	while (idx > 0)
	{
		nbr = ft_atoi(argv[idx]);
		if (nbr == 0 && *argv[idx] != '0')
			handle_error(a, b);
		a->numbers[idx - 1] = nbr;
		a->bottom++;
		idx--;
	}
	if (has_duplicates(a->numbers, argc - 1))
		handle_error(a, b);
}

void	handle_error(t_stack *a, t_stack *b)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	free_stacks(a, b);
	exit(EXIT_FAILURE);
}

void	free_stacks(t_stack *a, t_stack *b)
{
	if (a->numbers != NULL && b->numbers != NULL)
	{
		free(a->numbers);
		free(b->numbers);
	}
	else if (a->numbers != NULL && b->numbers == NULL)
		free(a->numbers);
	else
		free(b->numbers);
}
