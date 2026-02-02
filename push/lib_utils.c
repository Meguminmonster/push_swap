/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedra-v <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 13:30:35 by jpedra-v          #+#    #+#             */
/*   Updated: 2026/02/02 13:40:45 by jpedra-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, &*s, 1);
		s++;
	}
}

int	absolute(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

long int	ft_atoi(const char *s)
{
	long int	r;
	int			sg;

	r = 0;
	sg = 1;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sg = -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		r = (r * 10) + (*s - '0');
		s++;
	}
	return (sg * r);
}

int	ft_streq(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
