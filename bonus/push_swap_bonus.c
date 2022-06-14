/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 13:20:53 by njohanne          #+#    #+#             */
/*   Updated: 2022/05/26 17:49:44 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	stack->name = 'T';
	return (1);
}

int	check_arv(t_stack *a, t_stack *b, char **arv)
{
	a->arr = ft_pars_arv(arv, a->max_size);
	a->cur_size = a->max_size;
	a->name = 'T';
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

	str = ft_parser_str(arg, arv, &a);
	if (!check_arv(&a, &b, str))
		return (0);
	ft_parse(&a, &b);
	free(a.arr);
	free(b.arr);
	return (0);
}
