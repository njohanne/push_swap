/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pars_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 14:08:45 by njohanne          #+#    #+#             */
/*   Updated: 2022/04/04 14:21:39 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_pars_atoi(char *str, int	*array)
{
	int		i;
	int		poz;
	long	num;

	i = 0;
	poz = 1;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			poz *= -1;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + str[i] - 48;
		i++;
	}
	num *= poz;
	if (str[i] != '\0' || num < -2147483648 || num > 2147483647)
		return (0);
	*array = (int)num;
	return (1);
}
