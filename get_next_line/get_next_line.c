/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njohanne <njohanne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 22:05:32 by njohanne          #+#    #+#             */
/*   Updated: 2022/05/25 12:09:16 by njohanne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_copy_ost(char *ost)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!ost)
		return (NULL);
	while (ost[i] != '\n' && ost[i])
		i++;
	if (!ost[i])
	{
		free(ost);
		return (NULL);
	}
	i++;
	str = (char *)malloc(sizeof(char) * (ft_strlen(ost) - i + 1));
	while (ost[i] != '\0')
		str[j++] = ost[i++];
	str[j] = '\0';
	free(ost);
	return (str);
}

char	*ft_copy_str(char *ost)
{
	int		i;
	char	*str;

	i = 0;
	if (!ost)
		return (NULL);
	if (ost[0] == '\0')
		return (NULL);
	while (ost[i] != '\n' && ost[i] != '\0')
		i++;
	if (ost[i] == '\n')
		i++;
	str = (char *)malloc(sizeof(char *) * (i + 1));
	str[i--] = '\0';
	while (i >= 0)
	{
		str[i] = ost[i];
		i--;
	}
	return (str);
}

int	find_end(char *buf)
{
	int	i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_gnl(int fd, char *ost)
{
	int			dl;
	char		*buf;
	int			flag;

	flag = 1;
	dl = 1;
	buf = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	while (flag && dl != 0)
	{
		dl = read(fd, buf, BUFFER_SIZE);
		if (dl == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[dl] = '\0';
		if (dl > 0 && !ost)
			ost = ft_create_ost(ost);
		if (dl > 0)
			ost = ft_strjoin(ost, buf);
		flag = find_end(ost);
	}
	free(buf);
	return (ost);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*ost;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ost = ft_gnl(fd, ost);
	str = ft_copy_str(ost);
	ost = ft_copy_ost(ost);
	return (str);
}
