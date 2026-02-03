/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:11:20 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/02/02 12:58:42 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Shifts all elements down by 1; the last element becomes the first (rra/rrb).
static void	reverse(t_stack **top)
{
	t_stack	*ex_top;
	t_stack	*new_bottom;
	t_stack	*ex_bottom;

	ex_bottom = *top;
	new_bottom = *top;
	ex_top = *top;
	while (ex_bottom->next)
		ex_bottom = ex_bottom->next;
	while (new_bottom->next->next)
		new_bottom = new_bottom->next;
	*top = ex_bottom;
	(*top)->next = ex_top;
	new_bottom->next = NULL;
}

// Shifts all elements up by 1; the first element becomes the last (ra/rb).
static void	rotate(t_stack **top)
{
	t_stack	*ex_top;
	t_stack	*bottom;

	ex_top = *top;
	*top = (*top)->next;
	bottom = *top;
	while (bottom->next)
		bottom = bottom->next;
	ex_top->next = NULL;
	bottom->next = ex_top;
}

// Calls 'ra', 'rb', 'rr', 'rra', 'rrb', 'rrr' operations.
void	rotate_move(t_stack **sa, t_stack **sb, char *choice, int print)
{
	if (ft_strcmp(choice, "ra") == 0)
		rotate(sa);
	else if (ft_strcmp(choice, "rb") == 0)
		rotate(sb);
	else if (ft_strcmp(choice, "rr") == 0)
	{
		rotate(sa);
		rotate(sb);
	}
	else if (ft_strcmp(choice, "rra") == 0)
		reverse(sa);
	else if (ft_strcmp(choice, "rrb") == 0)
		reverse(sb);
	else if (ft_strcmp(choice, "rrr") == 0)
	{
		reverse(sa);
		reverse(sb);
	}
	if (print)
	{
		ft_putstr(choice);
		ft_putstr("\n");
	}
}
