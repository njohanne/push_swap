/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 12:19:24 by njohanne          #+#    #+#             */
/*   Updated: 2022/05/26 17:38:13 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*z1;
	unsigned char	*z2;

	z1 = (unsigned char *)s1;
	z2 = (unsigned char *)s2;
	if (*z1 == '\0')
		return (-(*z2));
	if (*z2 == '\0')
		return (*z1);
	while (*z1 != '\0' || *z2 != '\0')
	{
		if (*z1 != *z2)
			return (*z1 - *z2);
		z1++;
		z2++;
	}
	return (0);
}

static void	ft_free(t_stack *a, t_stack *b)
{
	free(a->arr);
	free(b->arr);
	ft_error();
}

static void	check_stacks(char *line, t_stack *a, t_stack *b)
{
	if (!(ft_strcmp(line, "sa\n")))
		ft_sa_sb(a, 1);
	else if (!(ft_strcmp(line, "sb\n")))
		ft_sa_sb(b, 1);
	else if (!(ft_strcmp(line, "ss\n")))
		ft_ss(a, b, 1);
	else if (!(ft_strcmp(line, "pa\n")))
		ft_pa_pb(b, a);
	else if (!(ft_strcmp(line, "pb\n")))
		ft_pa_pb(a, b);
	else if (!(ft_strcmp(line, "ra\n")))
		ft_ra_rb(a, 1);
	else if (!(ft_strcmp(line, "rb\n")))
		ft_ra_rb(b, 1);
	else if (!(ft_strcmp(line, "rr\n")))
		ft_rr(a, b, 1);
	else if (!(ft_strcmp(line, "rra\n")))
		ft_rra_rrb(a, 1);
	else if (!(ft_strcmp(line, "rrb\n")))
		ft_rra_rrb(b, 1);
	else if (!(ft_strcmp(line, "rrr\n")))
		ft_rrr(a, b, 1);
	else
		ft_free(a, b);
}

void	ft_parse(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		check_stacks(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	if (b->cur_size == 0 && ft_array_sorted(*a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}
