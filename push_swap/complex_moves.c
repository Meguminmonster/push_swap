/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:10:33 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/01/30 14:37:34 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Finds the element with the lowest index in the stack.
int	get_lower_position(t_stack **st)
{
	t_stack	*s;
	int		low_index;
	int		low_position;

	s = *st;
	low_index = INT_MAX;
	get_stack_positions(st);
	low_position = s->position;
	while (s)
	{
		if (s->main_index < low_index)
		{
			low_index = s->main_index;
			low_position = s->position;
		}
		s = s->next;
	}
	return (low_position);
}

// Rotates stack A at the end of sorting so the smallest element is at the top.
static void	last_rotates(t_stack **sa)
{
	int	size;
	int	lower_position;

	size = get_stack_size(*sa);
	lower_position = get_lower_position(sa);
	if (lower_position > size / 2)
	{
		while (lower_position++ < size)
			rotate_move(sa, NULL, "rra", 1);
	}
	else
	{
		while (lower_position--)
			rotate_move(sa, NULL, "ra", 1);
	}
}

// Pushes almost all elements from A to B.
static void	push_b_save_3(t_stack **sa, t_stack **sb)
{
	int	size;
	int	pushed;
	int	i;

	size = get_stack_size(*sa);
	pushed = 0;
	i = 0;
	while (size > 6 && i < size && pushed < size / 2)
	{
		if ((*sa)->main_index <= size / 2)
		{
			swap_move(sa, sb, "pb", 1);
			pushed++;
		}
		else
			rotate_move(sa, NULL, "ra", 1);
		i++;
	}
	while (size - pushed > 3)
	{
		swap_move(sa, sb, "pb", 1);
		pushed++;
	}
	small_sort(sa);
}

// Pushes to B, calculates costs, and pushes to A in optimal order.
void	big_sort(t_stack **sa, t_stack **sb)
{
	push_b_save_3(sa, sb);
	while (*sb)
	{
		where_fit_in_a(sa, sb);
		calculate_moves(sa, sb);
		less_moves_sort(sa, sb);
	}
	if (!is_sorted(*sa))
		last_rotates(sa);
}
