/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:06:18 by njohanne          #+#    #+#             */
/*   Updated: 2022/05/26 17:49:26 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_max_size(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	**ft_parser_str(int arg, char **arv, t_stack *stack)
{
	char	**str;
	int		i;
	char	*spase;
	char	*one_str;

	i = 1;
	spase = ft_strdup(" ");
	one_str = NULL;
	while (--arg)
	{
		one_str = ft_strjoin(one_str, arv[i++]);
		one_str = ft_strjoin(one_str, spase);
		if (!one_str)
			return (NULL);
	}
	str = ft_split(one_str, ' ');
	stack->max_size = ft_max_size(str);
	free(spase);
	free(one_str);
	return (str);
}
