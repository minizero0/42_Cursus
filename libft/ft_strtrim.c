/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeocho <yeocho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 15:16:06 by yeocho            #+#    #+#             */
/*   Updated: 2022/01/21 11:59:08 by yeocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*ret;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (ft_strchr(set, s1[end]) && end >= start && s1[end])
		end--;
	if (start >= end)
		return (ft_strdup(""));
	ret = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1 + start, end - start + 2);
	return (ret);
}
