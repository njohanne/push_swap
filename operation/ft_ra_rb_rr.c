/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_rb_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 21:20:08 by njohanne          #+#    #+#             */
/*   Updated: 2022/04/01 18:55:07 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra_rb(t_stack *stack, int same)
{
	int	num;
	int	i;

	num = stack->arr[0];
	i = 0;
	while (i != stack->cur_size)
	{
		stack->arr[i] = stack->arr[i + 1];
		i++;
	}
	stack->arr[i - 1] = num;
	if (stack->name == 'a' && same == 0)
		ft_putstr("ra\n");
	if (stack->name == 'b' && same == 0)
		ft_putstr("rb\n");
}

void	ft_rr(t_stack *a, t_stack *b, int check)
{
	ft_ra_rb(a, 1);
	ft_ra_rb(b, 1);
	if (!check)
		ft_putstr("rr\n");
}
