/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:11:12 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/01/29 15:31:08 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *st)
{
	t_stack	*s;

	s = st;
	while (s->next)
	{
		if (s->n > s->next->n)
			return (0);
		s = s->next;
	}
	return (1);
}

static void	push_swap(t_stack **sa, t_stack **sb, int size)
{
	if (size == 2 && !is_sorted(*sa))
		swap_move(sa, NULL, "sa");
	else if (size == 3)
		small_sort(sa);
	else if (size > 3 && !is_sorted(*sa))
		big_sort(sa, sb);
}

int	main(int ac, char **av)
{
	t_stack	*sa;
	t_stack	*sb;
	int		size;

	if (ac < 2)
		return (0);
	if (!is_correct_input(av))
		print_error_and_exit(NULL, NULL);
	sa = create_stack(ac, av);
	sb = NULL;
	size = get_stack_size(sa);
	get_main_index(sa, size);
	push_swap(&sa, &sb, size);
	free_stack(&sa);
	free_stack(&sb);
}
