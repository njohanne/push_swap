/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minisort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:52:57 by njohanne          #+#    #+#             */
/*   Updated: 2022/04/04 14:34:07 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sort_tre(t_stack *stack)
{
	if (ft_array_sorted(*stack))
		return ;
	if (stack->cur_size == 2)
	{
		ft_sa_sb(stack, 0);
		return ;
	}
	while (!ft_array_sorted(*stack))
	{
		if (stack->arr[0] > stack->arr[1] && stack->arr[0] > stack->arr[2])
			ft_ra_rb(stack, 0);
		else if (stack->arr[0] < stack->arr[1] && stack->arr[0] > stack->arr[2])
			ft_rra_rrb(stack, 0);
		else
			ft_sa_sb(stack, 0);
	}
}

static void	ft_merge(t_stack *a, t_stack *b)
{
	int	max_a;

	max_a = a->arr[a->cur_size - 1];
	while (b->cur_size > 0)
	{
		if (a->arr[0] > b->arr[0] || (b->arr[0] > max_a
				&& a->arr[0] == a->min_num))
			ft_pa_pb(b, a);
		ft_ra_rb(a, 0);
	}
	while (a->arr[0] != a->min_num)
		ft_ra_rb(a, 0);
}

void	ft_minisort(t_stack *a, t_stack *b)
{
	if (a->cur_size == 2)
	{
		ft_sa_sb(a, 0);
		return ;
	}
	while (a->cur_size > 3)
		ft_pa_pb(a, b);
	ft_sort_tre(a);
	ft_sort_tre(b);
	ft_merge(a, b);
}
