/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phanosek <phanosek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 15:13:58 by phanosek          #+#    #+#             */
/*   Updated: 2023/10/01 15:29:21 by phanosek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/get_next_line.h"

char	*from_stash(char *stash)
{
	int		i;
	int		j;
	char	*read_line;

	i = 0;
	j = 0;
	if (stash[i] == '\0')
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	read_line = (char *)malloc(i + 2);
	if (read_line == NULL)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		read_line[j++] = stash[i++];
	if (stash[i] == '\n')
		read_line[j++] = stash[i++];
	read_line[j] = '\0';
	return (read_line);
}

char	*get_rest(char *stash)
{
	int		i;
	int		j;
	char	*rest_of_stash;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	rest_of_stash = (char *)malloc(ft_strlen(stash) - i + 1);
	if (rest_of_stash == NULL)
		return (NULL);
	i++;
	while (stash[i] != '\0')
		rest_of_stash[j++] = stash[i++];
	rest_of_stash[j] = '\0';
	free(stash);
	return (rest_of_stash);
}

char	*file_read(int fd, char *stash)
{
	int		a;
	char	*buf;

	a = 1;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	while (a > 0 && !ft_strchr(stash, '\n'))
	{
		a = read(fd, buf, BUFFER_SIZE);
		if (a == -1)
		{
			free(buf);
			return (0);
		}
		buf[a] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stash = file_read(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = from_stash(stash);
	stash = get_rest(stash);
	return (line);
}
