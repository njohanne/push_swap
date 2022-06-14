/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 23:03:56 by njohanne          #+#    #+#             */
/*   Updated: 2022/05/26 17:45:48 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_create_ost(char *ost)
{
	ost = malloc(sizeof(char *));
	ost[0] = '\0';
	return (ost);
}
