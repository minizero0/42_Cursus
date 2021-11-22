/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeocho <yeocho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:17:32 by yeocho            #+#    #+#             */
/*   Updated: 2021/11/22 15:30:42 by yeocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len1;
	size_t	len2;
	size_t	index;

	index = 0;
	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	if (!dstsize)
		return (len2);
	if (dstsize <= dst_len)
		return (len1 + len2);
	while (*dst)
		dst++;
	while (src[index] && index < (dstsize - len1 - 1))
	{
		*dst = src[index];
		index++;
		dst++;
	}
	*dst = '\0';
	return (len1 + len2);
}
