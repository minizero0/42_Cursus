/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeocho <yeocho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:54:31 by yeocho            #+#    #+#             */
/*   Updated: 2022/04/15 00:09:18 by yeocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	is_newline(char *buf)
{
	int	index;

	index = -1;
	while (buf[++index])
	{
		if (buf[index] == '\n')
			return (index);
	}
	return (-1);
}

static char	*split_line(char **backbuf, char *buf)
{
	char	*line;
	int		index;
	char	*temp;

	line = NULL;
	index = is_newline(*backbuf);
	if (index == -1)
	{
		if (*backbuf[0] != 0)
			line = ft_strndup(*backbuf, 0, ft_strlen(*backbuf));
		free(*backbuf);
		*backbuf = NULL;
	}
	else
	{
		line = ft_strndup(*backbuf, 0, index + 1);
		temp = ft_strndup(*backbuf, index + 1, ft_strlen(*backbuf) - index - 1);
		free(*backbuf);
		*backbuf = temp ;
	}
	free(buf);
	return (line);
}

static char	*read_line(int fd, char *buf, char **backup)
{
	char		*new_backup;
	int			read_size;

	read_size = read(fd, buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		buf[read_size] = 0;
		new_backup = ft_strjoin(*backup, buf);
		free(*backup);
		*backup = new_backup;
		if (is_newline(*backup) != -1)
			return (split_line(backup, buf));
		read_size = read(fd, buf, BUFFER_SIZE);
	}
	return (split_line(backup, buf));
}

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*backup;

	buf = (char *) malloc (BUFFER_SIZE + 1);
	if (buf == NULL)
		return (0);
	if (BUFFER_SIZE == 0 || read(fd, buf, 0) == -1)
	{
		free(buf);
		return (0);
	}
	if (backup != NULL && is_newline(backup) != -1)
		return (split_line (&backup, buf));
	if (backup == 0)
		backup = ft_strndup("", 0, 0);
	return (read_line(fd, buf, &backup));
}
