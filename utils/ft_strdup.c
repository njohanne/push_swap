/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:40:24 by njohanne          #+#    #+#             */
/*   Updated: 2022/05/26 16:25:24 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

size_t	ft_strlcpy(char *dest, const char *source, size_t n)
{
	size_t	i;

	i = 0;
	if (n > 0)
	{
		while (i < (n - 1) && source[i] != '\0')
		{
			dest[i] = source[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (source[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	size_t	i;

	i = ft_strlen(str);
	dup = (char *)malloc(i + 1);
	if (dup == NULL)
		return (NULL);
	ft_strlcpy(dup, str, i + 1);
	return (dup);
}
