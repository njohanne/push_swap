/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_ready.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 15:45:23 by njohanne          #+#    #+#             */
/*   Updated: 2022/04/04 14:31:52 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_array_sorted(t_stack stack)
{
	int	i;

	i = 0;
	while (i < stack.cur_size - 1)
	{
		if (stack.arr[i] > stack.arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_array_ready(t_stack stack)
{
	if (stack.cur_size == stack.max_size)
		return (1);
	return (0);
}
