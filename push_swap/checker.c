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

// Parses/Unifies arguments and validates them
static char	**get_args(int ac, char **av)
{
	char	**args;
	char	*all;
	char	*tmp;
	int		i;

	if (ac == 2)
		args = ft_split(av[1], ' ');
	else
	{
		i = 1;
		all = ft_calloc(1, 1);
		while (i < ac)
		{
			tmp = ft_strjoin(all, " ");
			free(all);
			all = ft_strjoin(tmp, av[i++]);
			free(tmp);
		}
		args = ft_split(all, ' ');
		free(all);
	}
	if (!args || !is_correct_input(args))
		print_error_and_exit(NULL, NULL);
	return (args);
}

// Checks if the read command is a valid Push Swap operation.
static int	is_valid_cmd(char *s)
{
	if (ft_strcmp(s, "sa") && ft_strcmp(s, "sb") && ft_strcmp(s, "ss")
		&& ft_strcmp(s, "pa") && ft_strcmp(s, "pb")
		&& ft_strcmp(s, "ra") && ft_strcmp(s, "rb") && ft_strcmp(s, "rr")
		&& ft_strcmp(s, "rra") && ft_strcmp(s, "rrb") && ft_strcmp(s, "rrr"))
		return (0);
	return (1);
}

// Cleans the command (removes \n), validates, and executes the move.
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

// Main loop: reads instructions from stdin until EOF (Ctrl+D).
static void	process_lines(t_stack **sa, t_stack **sb)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		execute(sa, sb, line);
		free(line);
	}
}

// Main function: Initializes, processes, and verifies the final result.
int	main(int ac, char **av)
{
	t_stack	*sa;
	t_stack	*sb;
	char	**args;

	if (ac < 2)
		return (0);
	args = get_args(ac, av);
	sa = create_stack(0, args);
	free_matrix(args);
	if (!sa)
		return (0);
	sb = NULL;
	process_lines(&sa, &sb);
	if (is_sorted(sa) && !sb)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&sa);
	free_stack(&sb);
	return (0);
}
