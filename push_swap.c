/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:34:59 by njohanne          #+#    #+#             */
/*   Updated: 2022/06/14 13:59:48 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_repeat(t_stack *stack)
{
	int	size;
	int	i;
	int	j;

	size = stack->max_size;
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack->arr[i] == stack->arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*ft_pars_arv(char **arv, int size)
{
	int	*array;
	int	i;

	i = 0;
	array = (int *)malloc(sizeof(int) * size);
	if (array == NULL)
		ft_error();
	while (size > i)
	{
		if (!ft_pars_atoi(arv[i], &array[i]))
			ft_error();
		i++;
	}
	return (array);
}

int	ft_create_b(t_stack *stack, int size)
{
	int	i;

	i = 0;
	stack->arr = (int *)malloc(sizeof(int) * size);
	if (stack->arr == NULL)
		return (0);
	while (i < size)
	{
		stack->arr[i] = 0;
		i++;
	}
	stack->cur_size = 0;
	stack->max_size = size;
	stack->name = 'b';
	return (1);
}

int	check_arv(t_stack *a, t_stack *b, char **arv)
{
	a->arr = ft_pars_arv(arv, a->max_size);
	a->cur_size = a->max_size;
	a->name = 'a';
	if (!a->arr || !ft_repeat(a))
	{
		free(a->arr);
		ft_error();
		return (0);
	}
	if (!ft_create_b(b, a->max_size))
	{
		free(a->arr);
		free(b->arr);
		ft_error();
		return (0);
	}
	return (1);
}

int	main(int arg, char **arv)
{
	t_stack	a;
	t_stack	b;
	char	**str;

	if (arg == 1)
		ft_error();
	str = ft_parser_str(arg, arv, &a);
	if (!str)
		return (0);
	if (!check_arv(&a, &b, str))
		return (0);
	if (ft_array_sorted(a) && ft_array_ready(a))
	{
		free(a.arr);
		free(b.arr);
		return (0);
	}
	else if (a.cur_size <= 6)
	{
		a.min_num = ft_find_min(a);
		ft_minisort(&a, &b);
	}
	else
		ft_full_sort(&a, &b);
	free(a.arr);
	free(b.arr);
	return (0);
}
