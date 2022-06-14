/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:54:12 by njohanne          #+#    #+#             */
/*   Updated: 2022/04/04 14:31:24 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_find_min(t_stack stack)
{
	int	min;
	int	i;

	i = 0;
	min = stack.arr[i++];
	while (i < stack.cur_size)
	{
		if (min > stack.arr[i])
			min = stack.arr[i];
		i++;
	}
	return (min);
}

int	ft_find_max(t_stack stack)
{
	int	max;
	int	i;

	i = 0;
	max = stack.arr[i];
	while (i < stack.cur_size)
	{
		if (max < stack.arr[i])
			max = stack.arr[i];
		i++;
	}
	return (max);
}
