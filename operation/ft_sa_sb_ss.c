/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_sb_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:00:16 by njohanne          #+#    #+#             */
/*   Updated: 2022/05/25 14:04:32 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa_sb(t_stack *stack, int same)
{
	int	num;

	if (!stack || stack->cur_size < 2)
		return ;
	num = stack->arr[0];
	stack->arr[0] = stack->arr[1];
	stack->arr[1] = num;
	if (stack->name == 'a' && same == 0)
		ft_putstr("sa\n");
	else if (stack->name == 'b' && same == 0)
		ft_putstr("sb\n");
}

void	ft_ss(t_stack *a, t_stack *b, int check)
{
	ft_sa_sb(a, 1);
	ft_sa_sb(b, 1);
	if (!check)
		ft_putstr("ss\n");
}
