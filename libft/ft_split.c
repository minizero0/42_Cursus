/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeocho <yeocho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:12:57 by yeocho            #+#    #+#             */
/*   Updated: 2022/01/21 12:13:14 by yeocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	count_word(char const *s, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	if (*s == '\0')
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static int	count_ch(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	return (count);
}

static char	**malloc_error(char **ret, int i)
{
	int		j;

	if (!ret)
	{
		j = 0;
		while (j < i)
			free(ret[j++]);
		free(ret);
		return (NULL);
	}
	else
		return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	ret = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (*s)
	{
		j = 0;
		while (*s && *s == c)
			s++;
		if (!count_ch(s, c))
			break ;
		ret[i] = (char *)malloc(sizeof(char) * (count_ch(s, c) + 1));
		malloc_error(ret, i);
		while (*s && *s != c)
			ret[i][j++] = *s++;
		ret[i++][j] = '\0';
	}
	ret[i] = NULL;
	return (ret);
}
