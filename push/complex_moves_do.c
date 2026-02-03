/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_moves_do.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:10:43 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/01/30 14:38:31 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Optimizes by executing 'rrr' when both stacks need reverse rotation.
static void	reverse_both(t_stack **sa, t_stack **sb, int *mv_a, int *mv_b)
{
	while (*mv_a < 0 && *mv_b < 0)
	{
		(*mv_a)++;
		(*mv_b)++;
		rotate_move(sa, sb, "rrr", 1);
	}
}

// Optimizes by executing 'rr' when both stacks need rotation.
static void	rotate_both(t_stack **sa, t_stack **sb, int *mv_a, int *mv_b)
{
	while (*mv_a > 0 && *mv_b > 0)
	{
		(*mv_a)--;
		(*mv_b)--;
		rotate_move(sa, sb, "rr", 1);
	}
}

// Rotates stack A the required amount to prepare for a push operation.
static void	rotate_a(t_stack **sa, int *mv_a)
{
	while (*mv_a)
	{
		if (*mv_a > 0)
		{
			rotate_move(sa, NULL, "ra", 1);
			(*mv_a)--;
		}
		else if (*mv_a < 0)
		{
			rotate_move(sa, NULL, "rra", 1);
			(*mv_a)++;
		}
	}
}

// Rotates stack B the required amount to move the target element to the top.
static void	rotate_b(t_stack **sb, int *mv_b)
{
	while (*mv_b)
	{
		if (*mv_b > 0)
		{
			rotate_move(NULL, sb, "rb", 1);
			(*mv_b)--;
		}
		else if (*mv_b < 0)
		{
			rotate_move(NULL, sb, "rrb", 1);
			(*mv_b)++;
		}
	}
}

// Identifies and executes the cheapest move.
void	less_moves_sort(t_stack **sa, t_stack **sb)
{
	t_stack	*b;
	int		less_moves;
	int		mv_a;
	int		mv_b;

	b = *sb;
	less_moves = INT_MAX;
	while (b)
	{
		if (absolute(b->mv_a) + absolute(b->mv_b) < absolute(less_moves))
		{
			less_moves = absolute(b->mv_a) + absolute(b->mv_b);
			mv_a = b->mv_a;
			mv_b = b->mv_b;
		}
		b = b->next;
	}
	if (mv_a < 0 && mv_b < 0)
		reverse_both(sa, sb, &mv_a, &mv_b);
	else if (mv_a > 0 && mv_b > 0)
		rotate_both(sa, sb, &mv_a, &mv_b);
	rotate_a(sa, &mv_a);
	rotate_b(sb, &mv_b);
	swap_move(sa, sb, "pa", 1);
}
