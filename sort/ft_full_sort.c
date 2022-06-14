/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_full_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 14:29:08 by njohanne          #+#    #+#             */
/*   Updated: 2022/04/04 15:56:10 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_cheak_step(int size, int n)
{
	int	step;

	if (n > size / 2)
		step = size - n;
	else
		step = n;
	return (step);
}

void	ft_finish(int count_a, int count_b, t_stack *a, t_stack *b)
{
	int	num_a;
	int	num_b;

	num_a = a->arr[count_a];
	num_b = b->arr[count_b];
	if (count_a <= (a->cur_size / 2)
		&& count_b <= (b->cur_size / 2))
		while (a->arr[0] != num_a && b->arr[0] != num_b)
			ft_rr(a, b, 0);
	else if (count_a >= (a->cur_size / 2) && count_b >= (b->cur_size / 2))
		while (a->arr[0] != num_a && b->arr[0] != num_b)
			ft_rrr(a, b, 0);
	if (count_b <= (b->cur_size / 2))
		while (b->arr[0] != num_b)
			ft_ra_rb(b, 0);
	else if (count_b >= (b->cur_size / 2))
		while (b->arr[0] != num_b)
			ft_rra_rrb(b, 0);
	if (count_a <= (a->cur_size / 2))
		while (a->arr[0] != num_a)
			ft_ra_rb(a, 0);
	else if (count_a >= (a->cur_size / 2))
		while (a->arr[0] != num_a)
			ft_rra_rrb(a, 0);
	ft_pa_pb(b, a);
}

int	ft_step(int i, t_stack *a, t_stack *b)
{
	int	step;
	int	j;

	if (b->arr[i] < a->arr[0] && b->arr[i] > a->arr[a->cur_size - 1])
	{
		step = ft_cheak_step(b->cur_size, i)
			+ ft_cheak_step(a->cur_size, 0);
		a->lol = 0;
	}
	else
	{
		j = 0;
		while (++j < a->cur_size)
		{
			if (b->arr[i] > a->arr[j - 1] && b->arr[i] < a->arr[j])
			{
				step = ft_cheak_step(b->cur_size, i)
					+ ft_cheak_step(a->cur_size, j);
				a->lol = j;
				break ;
			}
		}
	}
	return (step);
}

void	ft_min_step(t_stack *a, t_stack *b)
{
	int	i;
	int	min_step;
	int	step;

	i = -1;
	min_step = 2147483647;
	while (++i < b->cur_size)
	{
		step = ft_step(i, a, b);
		if (min_step > step)
		{
			min_step = step;
			a->count_step = a->lol;
			b->count_step = i;
		}
	}
	ft_finish(a->count_step, b->count_step, a, b);
}

void	ft_full_sort(t_stack *a, t_stack *b)
{
	int	i_min;

	i_min = 0;
	a->min_num = ft_find_min(*a);
	a->max_num = ft_find_max(*a);
	while (a->cur_size > 2)
	{
		if (a->arr[0] == a->min_num || a->arr[0] == a->max_num)
			ft_ra_rb(a, 0);
		else
			ft_pa_pb(a, b);
	}
	while (b->cur_size != 0)
		ft_min_step(a, b);
	while (a->arr[i_min] != a->min_num)
		i_min++;
	if (i_min < (a->cur_size / 2))
		while (a->arr[0] != a->min_num)
			ft_ra_rb(a, 0);
	else
		while (a->arr[0] != a->min_num)
			ft_rra_rrb(a, 0);
}
