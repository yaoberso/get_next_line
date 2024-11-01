/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yann <yann@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:57:04 by yaoberso          #+#    #+#             */
/*   Updated: 2024/11/01 11:14:42 by yann             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_join(int fd, char *content, char *buffer)
{
	int			bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		content = ft_strjoin(content, buffer);
		if (content == NULL)
		{
			/*free(buffer);*/
			return (NULL);
		}
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (bytes_read < 0)
	{
		free(content);
		return (NULL);
	}
	return (content);
}

char	*ft_in_txt(int fd)
{
	static char	*buffer;
	char		*content;

	content = NULL;
	buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	content = read_and_join(fd, content, buffer);
	/*free(buffer);*/
	return (content);
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*strm;
	int		len;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	strm = malloc(len + 1);
	if (strm == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		strm[i] = str[i];
		i++;
	}
	strm[len] = '\0';
	return (strm);
}

int	ft_strlen(const char *str)
{
	int		i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == NULL)
		s1 = ft_strdup("");
	if (s2 == NULL || s1 == NULL)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
	{
		free(s1);
		return (NULL);
	}
	while (s1[i] != '\0')
		str[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	return (str);
}
