/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeocho <yeocho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:48:12 by yeocho            #+#    #+#             */
/*   Updated: 2022/04/14 23:50:36 by yeocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
		length++;
	return (length);
}

char	*ft_strndup(const char *src, int start, int num)
{
	char	*temp;
	int		index;
	int		len;

	index = 0;
	len = 0;
	temp = (char *)malloc(num + 1);
	if (temp == NULL)
		return (NULL);
	while (src[index] && len < num)
		temp[len++] = src[start + index++];
	temp[len] = 0;
	return (temp);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		index;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = (char *) malloc(sizeof(char) * (s1_len + s2_len + 2));
	if (new == NULL)
		return (NULL);
	index = 0;
	while (*s1)
	{
		new[index++] = *s1;
		s1++;
	}
	while (*s2)
	{
		new[index++] = *s2;
		s2++;
	}
	new[index] = '\0';
	return (new);
}
