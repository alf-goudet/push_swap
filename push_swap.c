/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agoudet- <agoudet-@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 20:12:31 by agoudet-          #+#    #+#             */
/*   Updated: 2026/04/07 20:58:10 by agoudet-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stacks(t_stack a, t_stack b);

static void	initialise_stacks(t_stack a, t_stack b, int argc, char **argv); 

int	main(int argc, char **argv)
{
	int	idx;
	t_stack	a;
	t_stack	b;

	a.numbers = (int *)malloc((argc - 1) * sizeof(int) + 1);
	b.numbers = (int *)malloc(1);
	if (a.numbers == NULL || b.numbers == NULL)
	{
		write(STDERR_FILENO, "Error\n", 6);
		free_stacks(a, b);
		return (1);
	}
	initialise_stacks(a, b, argc, argv);
	idx = 1;
	ft_printf("Top stack number: %d\n", *a.top);
	while (idx < argc)
	{
		ft_printf("%d\n", a.numbers[idx]);
		idx++;
	}
	free_stacks(a, b);
	return (0);
}

static void	free_stacks(t_stack a, t_stack b)
{
	if (a.numbers != NULL && b.numbers != NULL)
	{
		free(a.numbers);
		free(b.numbers);
	}
	else if (a.numbers != NULL && b.numbers == NULL)
		free(a.numbers);
	else
		free(b.numbers);	
}

static void	initialise_stacks(t_stack a, t_stack b, int argc, char **argv)
{
	int	idx;
	
	idx = argc;
	a.numbers[idx + 1] = '\0';
	while (idx > 0)
	{
		a.numbers[idx] = ft_atoi(argv[idx]);
		a.top = &a.numbers[idx];
		idx--;
	}
	*b.numbers = '\0';
}
