/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yann <yann@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:56:59 by yaoberso          #+#    #+#             */
/*   Updated: 2024/11/01 11:14:42 by yann             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	init_check(int fd, char **remain)
{
	if (*remain == NULL)
	{
		*remain = ft_in_txt(fd);
		if (*remain == NULL)
		{
			return (0);
		}
	}
	return (*remain && (*remain)[0] != '\0');
}

static int	find_newline(char *remain, int *newlfound)
{
	int		i;

	i = 0;
	*newlfound = 0;
	while (remain[i] != '\0')
	{
		if (remain[i] == '\n')
		{
			*newlfound = 1;
			break ;
		}
		i++;
	}
	return (i);
}

static char	*allocate_line(char *remain, int i, int newlfound)
{
	char	*line;
	int		j;

	j = 0;
	line = malloc(i + newlfound + 1);
	if (line == NULL)
	{
		return (NULL);
	}
	while (j < i)
	{
		line[j] = remain[j];
		j++;
	}
	if (newlfound)
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*update_remainder(char **remain, char *line, int i, int newlfound)
{
	char	*temp;

	if (newlfound)
	{
		temp = ft_strdup(*remain + i + 1);
		if (temp == NULL)
		{
			free(line);
			return (NULL);
		}
		free(*remain);
		*remain = temp;
	}
	else
	{
		free(*remain);
		*remain = NULL;
	}
	free(temp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remain = NULL;
	char		*line;
	int			i;
	int			newlfound;

	if (!init_check(fd, &remain))
	{
		free(remain);
		remain = NULL;
		return (NULL);
	}
	i = find_newline(remain, &newlfound);
	line = allocate_line(remain, i, newlfound);
	if (line == NULL)
	{
		free(remain);
		remain = NULL;
		return (NULL);
	}
	if (update_remainder(&remain, line, i, newlfound) == NULL)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
