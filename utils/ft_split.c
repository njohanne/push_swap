/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:20:18 by njohanne          #+#    #+#             */
/*   Updated: 2022/05/25 20:50:02 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_split_count(const char *s, char c)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (j != i)
			count++;
	}
	return (count);
}

void	ft_free_str(char **str, int j)
{
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
}

char	**ft_split_str(char **str, int count, const char *s, char c)
{
	int		end;
	int		j;
	int		start;

	j = 0;
	start = 0;
	while (j < count)
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		str[j] = (char *)malloc(sizeof(char) * (end - start + 1));
		if (str[j] == NULL)
			return (NULL);
		ft_strlcpy(str[j], &s[start], (end - start + 1));
		start = end;
		j++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		count;

	if (s == NULL)
		return (NULL);
	count = ft_split_count(s, c);
	str = (char **)malloc(sizeof(char *) * (count + 1));
	if (str == NULL)
		return (NULL);
	str[count] = NULL;
	str = ft_split_str(str, count, s, c);
	return (str);
}
