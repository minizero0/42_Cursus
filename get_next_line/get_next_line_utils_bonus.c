/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeocho <yeocho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:39:38 by yeocho            #+#    #+#             */
/*   Updated: 2022/04/07 21:39:42 by yeocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdlib.h>

static size_t
	ft_strlen(const char *s)
{
	size_t	index;

	index = 0;
	while (s[index])
		index++;
	return (index);
}

static void
	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

char
	*ft_strdup(const char *s1)
{
	char	*ret;
	int		index;
	int		len;

	len = ft_strlen(s1);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		ret[index] = s1[index];
		index++;
	}
	ret[index] = '\0';
	return (ret);
}

char
	*ft_strjoin(char *s1, char *s2)
{
	char	*ret;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!ret)
		return (NULL);
	ft_memcpy(ret, s1, s1_len);
	free(s1);
	ft_memcpy(ret + s1_len, s2, s2_len);
	ret[s1_len + s2_len] = '\0';
	return (ret);
}
