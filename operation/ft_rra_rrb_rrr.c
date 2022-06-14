/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra_rrb_rrr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 13:31:00 by njohanne          #+#    #+#             */
/*   Updated: 2022/04/01 18:55:23 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rra_rrb(t_stack *stack, int same)
{
	int	num;
	int	i;
	int	size;

	i = 0;
	size = stack->cur_size;
	num = stack->arr[size - 1];
	while (size)
	{
		stack->arr[size] = stack->arr[size - 1];
		size--;
	}
	stack->arr[0] = num;
	if (stack->name == 'a' && same == 0)
		ft_putstr("rra\n");
	else if (stack->name == 'b' && same == 0)
		ft_putstr("rrb\n");
}

void	ft_rrr(t_stack *a, t_stack *b, int check)
{
	ft_rra_rrb(a, 1);
	ft_rra_rrb(b, 1);
	if (!check)
		ft_putstr("rrr\n");
}
