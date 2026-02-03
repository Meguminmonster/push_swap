/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 12:44:52 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/02/02 12:44:54 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

// Verifies if the read string corresponds to a valid push_swap instruction.
static int	is_valid_cmd(char *s)
{
	if (!ft_streq(s, "sa") || !ft_streq(s, "sb") || !ft_streq(s, "ss"))
		return (1);
	if (!ft_streq(s, "pa") || !ft_streq(s, "pb"))
		return (1);
	if (!ft_streq(s, "ra") || !ft_streq(s, "rb") || !ft_streq(s, "rr"))
		return (1);
	if (!ft_streq(s, "rra") || !ft_streq(s, "rrb") || !ft_streq(s, "rrr"))
		return (1);
	return (0);
}

// Executes a single instruction on the stacks without printing output.
static void	execute(t_stack **sa, t_stack **sb, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	if (!is_valid_cmd(line))
	{
		free(line);
		print_error_and_exit(sa, sb);
	}
	if (line[0] == 's' || line[0] == 'p')
		swap_move(sa, sb, line, 0);
	else
		rotate_move(sa, sb, line, 0);
}

// Reads instructions from stdin, applies and verifies if the stack is sorted.
int	main(int ac, char **av)
{
	t_stack	*sa;
	t_stack	*sb;
	char	*line;

	if (ac < 2)
		return (0);
	if (!is_correct_input(av))
		print_error_and_exit(NULL, NULL);
	sa = create_stack(ac, av);
	sb = NULL;
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		execute(&sa, &sb, line);
		free(line);
	}
	if (is_sorted(sa) && sb == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&sa);
	free_stack(&sb);
	return (0);
}
