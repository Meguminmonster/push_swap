/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:11:03 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/01/29 16:40:08 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Assigns a rank to each number based on its value relative to others.
void	get_main_index(t_stack *sa, int size)
{
	t_stack	*a;
	t_stack	*max_address;
	int		max_n;

	while (size > 0)
	{
		a = sa;
		max_n = INT_MIN;
		max_address = NULL;
		while (a)
		{
			if (a->main_index == 0 && (max_address == NULL || a->n > max_n))
			{
				max_n = a->n;
				max_address = a;
			}
			a = a->next;
		}
		if (max_address)
			max_address->main_index = size;
		size--;
	}
}

// Returns the total number of elements currently in the stack.
int	get_stack_size(t_stack *st)
{
	t_stack	*s;
	int		size;

	size = 0;
	s = st;
	while (s)
	{
		size++;
		s = s->next;
	}
	return (size);
}

// Allocates memory for a new stack node and initializes.
static t_stack	*new_node(int n)
{
	t_stack	*s;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	s->n = n;
	s->main_index = 0;
	s->position = -1;
	s->where_fit = -1;
	s->mv_a = -1;
	s->mv_b = -1;
	s->next = NULL;
	return (s);
}

// Appends a new node to the end of the linked list.
static void	add_at_end(t_stack **st, t_stack *new)
{
	t_stack	*s;

	if (!new)
		return ;
	if (!*st)
		*st = new;
	else
	{
		s = *st;
		while (s->next)
			s = s->next;
		s->next = new;
	}
}

// Builds the initial stack A.
t_stack	*create_stack(int ac, char **av)
{
	t_stack		*sa;
	t_stack		*new;
	long int	n;
	int			i;

	(void)ac;
	sa = NULL;
	i = -1;
	while (av && av[++i])
	{
		n = ft_atoi(av[i]);
		if (n > INT_MAX || n < INT_MIN)
			print_error_and_exit(&sa, NULL);
		new = new_node((int)n);
		if (!new)
			print_error_and_exit(&sa, NULL);
		add_at_end(&sa, new);
	}
	return (sa);
}
