/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:11:12 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/01/30 14:35:59 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Chooses the sorting strategy
static void	push_swap(t_stack **sa, t_stack **sb, int size)
{
	if (size == 2 && !is_sorted(*sa))
		swap_move(sa, NULL, "sa", 1);
	else if (size == 3)
		small_sort(sa);
	else if (size > 3 && !is_sorted(*sa))
		big_sort(sa, sb);
}

static char	**join_and_split(int ac, char **av)
{
	char	*all;
	char	*tmp;
	char	**res;
	int		i;

	i = 1;
	all = ft_calloc(1, 1);
	while (i < ac)
	{
		tmp = ft_strjoin(all, " ");
		free(all);
		all = ft_strjoin(tmp, av[i++]);
		free(tmp);
	}
	res = ft_split(all, ' ');
	free(all);
	return (res);
}

static char	**get_valid_args(int ac, char **av)
{
	char	**args;

	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
		args = join_and_split(ac, av);
	if (!args || !is_correct_input(args))
	{
		if (args)
			free_matrix(args);
		print_error_and_exit(NULL, NULL);
	}
	return (args);
}

int	main(int ac, char **av)
{
	t_stack	*sa;
	t_stack	*sb;
	char	**args;
	int		size;

	if (ac < 2)
		return (0);
	args = get_valid_args(ac, av);
	sa = create_stack(0, args);
	free_matrix(args);
	size = get_stack_size(sa);
	if (!sa || size < 2 || is_sorted(sa))
	{
		free_stack(&sa);
		return (0);
	}
	sb = NULL;
	get_main_index(sa, size);
	push_swap(&sa, &sb, size);
	free_stack(&sa);
	free_stack(&sb);
	return (0);
}
