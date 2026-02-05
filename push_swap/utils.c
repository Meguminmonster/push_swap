/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:11:30 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/02/02 13:31:57 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_matrix(char **argv)
{
	int	i;

	i = 0;
	if (!argv)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

// Frees all memory allocated for the linked list.
void	free_stack(t_stack **st)
{
	t_stack	*temp;
	t_stack	*curr;

	if (!st || !*st)
		return ;
	curr = *st;
	while (curr)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	*st = NULL;
}

// Prints "Error", frees stacks, and terminates the program.
void	print_error_and_exit(t_stack **a, t_stack **b)
{
	if (!a || *a)
		free_stack(a);
	if (!b || *b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

// Checks if the stack is currently sorted in ascending order.
int	is_sorted(t_stack *st)
{
	if (!st || !st->next)
		return (1);
	while (st->next)
	{
		if (st->n > st->next->n)
			return (0);
		st = st->next;
	}
	return (1);
}
