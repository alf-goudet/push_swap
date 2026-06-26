/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 20:12:31 by agoudet-          #+#    #+#             */
/*   Updated: 2026/06/26 21:57:08 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	initialise_stacks(t_stack *a, t_stack *b, int argc, char **argv);

static bool	arg_is_digits_only(char *nbr_arg);

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
	int	i;
	int	nbr;

	a->numbers = (int *)ft_calloc(argc - 1, sizeof(int));
	b->numbers = (int *)ft_calloc(argc - 1, sizeof(int));
	if (a->numbers == NULL || b->numbers == NULL)
		handle_error(a, b);
	a->bottom = -1;
	b->bottom = -1;
	i = argc - 1;
	while (i > 0)
	{
		if (!arg_is_digits_only(argv[i]))
			handle_error(a, b);
		nbr = ft_atoi(argv[i]);
		if (nbr == 0 && *argv[i] != '0')
			handle_error(a, b);
		a->numbers[i - 1] = nbr;
		a->bottom++;
		i--;
	}
	if (has_duplicates(a->numbers, argc - 1))
		handle_error(a, b);
}

static bool	arg_is_digits_only(char *nbr_arg)
{
	int	i;

	i = 0;
	while (nbr_arg[i] != '\0')
	{
		if (!ft_isdigit(nbr_arg[i]))
			return (false);
		i++;
	}
	return (true);
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
