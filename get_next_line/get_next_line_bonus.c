/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeocho <yeocho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:40:06 by yeocho            #+#    #+#             */
/*   Updated: 2022/04/07 21:40:19 by yeocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>
#define FD_MAX 256

static int
	check_newline(char *buff)
{
	int	index;

	index = 0;
	while (buff[index])
	{
		if (buff[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

static int
	sep_line(char **line, char **store, int new_line)
{
	char	*temp;

	(*store)[new_line] = '\0';
	*line = ft_strdup(*store);
	if (!*line)
		return (-1);
	temp = ft_strdup(*store + new_line + 1);
	if (!temp)
		return (-1);
	free(*store);
	*store = temp;
	return (1);
}

static int
	remain_content(char **line, char **store, int read_size)
{
	int	i;

	if (read_size < 0)
	{
		if (*store)
			free(*store);
		return (-1);
	}
	if (*store && check_newline(*store) >= 0)
	{
		i = check_newline(*store);
		return (sep_line(line, store, i));
	}
	else if (*store)
	{
		*line = *store;
		*store = NULL;
		return (0);
	}
	*line = ft_strdup("");
	if (!*line)
		return (-1);
	return (0);
}

static char
	*check_valid(char *store[], char *buff, int *new_line, int fd)
{
	store[fd] = ft_strjoin(store[fd], buff);
	if (!store[fd])
		return (NULL);
	else
	{
		*new_line = check_newline(store[fd]);
		if (*new_line >= 0)
			free(buff);
		return (store[fd]);
	}
}

int
	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*store[FD_MAX];
	int			new_line;
	int			read_size;

	if ((fd < 0) || (BUFFER_SIZE <= 0) || !line || (FD_MAX <= fd))
		return (-1);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (-1);
	read_size = read(fd, buff, BUFFER_SIZE);
	while (read_size > 0)
	{
		buff[read_size] = '\0';
		store[fd] = check_valid(store, buff, &new_line, fd);
		if (!store[fd])
			return (-1);
		if (new_line >= 0)
			return (sep_line(line, &store[fd], new_line));
		read_size = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	return (remain_content(line, &store[fd], read_size));
}
