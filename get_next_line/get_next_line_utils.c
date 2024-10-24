/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaoberso <yaoberso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:57:04 by yaoberso          #+#    #+#             */
/*   Updated: 2024/10/24 13:55:58 by yaoberso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_in_txt(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*content;
	int		bytes_read;

	content = NULL;
	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[bytes_read] = '\0';
		content = ft_strjoin(content, buffer);
		if (content == NULL)
		{
			return (NULL);
		}
	}
	if (bytes_read < 0)
	{
		free(content);
		return (NULL);
	}
	return (content);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*strm;
	int		len;

	len = ft_strlen(str);
	strm = malloc(len + 1);
	if (strm == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0')
	{
		strm[i] = str[i];
		i++;
	}
	strm[i] = '\0';
	return (strm);
}

int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1 && s1[i] != '\0')
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2 && s2[i] != '\0')
	{
		str[j + j] = s2[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}

