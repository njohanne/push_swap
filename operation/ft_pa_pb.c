/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 20:22:11 by njohanne          #+#    #+#             */
/*   Updated: 2022/05/19 22:04:23 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_down(t_stack *stack, int size)
{
	size++;
	while (size--)
		stack->arr[size] = stack->arr[size - 1];
}

void	ft_top(t_stack *stack, int size)
{
	int	num;
	int	tnum;

	num = stack->arr[size];
	while (size--)
	{
		tnum = stack->arr[size];
		stack->arr[size] = num;
		num = tnum;
	}
	stack->cur_size--;
}

void	ft_pa_pb(t_stack *str, t_stack *dst)
{
	if (!str || !dst || str->cur_size == 0)
		return ;
	ft_down(dst, dst->cur_size);
	dst->arr[0] = str->arr[0];
	dst->cur_size++;
	ft_top(str, str->cur_size);
	if (dst->name == 'a')
		ft_putstr("pa\n");
	if (dst->name == 'b')
		ft_putstr("pb\n");
}
