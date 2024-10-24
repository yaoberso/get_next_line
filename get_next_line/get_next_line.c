/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:56:59 by yaoberso          #+#    #+#             */
/*   Updated: 2024/10/24 14:14:02 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*remainder;
	char		*line;
	char		*temp;
	int			i;
	int			j;
	int			newlfound;

	newlfound = 0;
	i = 0;
	remainder = NULL;
	line = NULL;
	temp = NULL;
	if (remainder == NULL)
	{
		remainder = ft_in_txt(fd);
		if (remainder == NULL)
			return (NULL);
	}
	if (remainder == NULL || remainder[0] == '\0')
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	while (remainder[i] != '\0')
	{
		if (remainder[i] != '\n')
		{
			newlfound = 1;
			break ;
		}
		i++;
	}
	line = malloc(i + newlfound + 1);
	if (line == NULL)
	{
		free (remainder);
		return (NULL);
	}
	j = 0;
	while (j < i)
	{
		line[j] = remainder[j];
		j++;
	}
	if (newlfound)
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	if (newlfound)
	{
		temp = ft_strdup(remainder + i);
		if (temp == NULL)
		{
			free (line);
			free (remainder);
			return (NULL);
		}
		free(remainder);
		remainder = temp;
	}
	else
	{
		free(remainder);
		remainder = NULL;
	}
	return (line);
}

