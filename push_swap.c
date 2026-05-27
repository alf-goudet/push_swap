/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 20:12:31 by agoudet-          #+#    #+#             */
/*   Updated: 2026/05/27 13:49:50 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initialise_stacks(t_stack *a, t_stack *b, int argc, char **argv);

static void	check_for_duplicates(t_stack *a, t_stack *b, int argc);

static void	free_stacks(t_stack *a, t_stack *b);

static void	handle_error(t_stack *a, t_stack *b);

int	main(int argc, char *argv[])
{
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		exit(EXIT_FAILURE);
	initialise_stacks(&a, &b, argc, argv);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	ss(&a, &b);
	rr(&a, &b);
	pa(&a, &b);
	rrr(&a, &b);
	pa(&a, &b);
	pa(&a, &b);
	pa(&a, &b);
	free_stacks(&a, &b);
	exit(EXIT_SUCCESS);
}

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
	check_for_duplicates(a, b, argc);
}

static void	check_for_duplicates(t_stack *a, t_stack *b, int argc)
{
	int	*temp_stack_cpy;

	temp_stack_cpy = (int *)ft_calloc(argc - 1, sizeof(int));
	if (temp_stack_cpy == NULL)
	{
		handle_error(a, b);
	}
	ft_memcpy(temp_stack_cpy, a->numbers, (argc - 1) * sizeof(int));
	if (has_duplicates(temp_stack_cpy, argc - 1))
	{
		free(temp_stack_cpy);
		handle_error(a, b);
	}
	free(temp_stack_cpy);
}

static void	handle_error(t_stack *a, t_stack *b)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	free_stacks(a, b);
	exit(EXIT_FAILURE);
}

static void	free_stacks(t_stack *a, t_stack *b)
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
