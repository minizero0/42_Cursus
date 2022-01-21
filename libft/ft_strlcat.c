/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeocho <yeocho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:17:32 by yeocho            #+#    #+#             */
/*   Updated: 2022/01/21 11:02:04 by yeocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	dst_len;
	size_t	src_len;

	index = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (*dst)
		dst++;
	while (src[index] && index < (dstsize - dst_len - 1))
	{
		*dst = src[index];
		index++;
		dst++;
	}
	*dst = '\0';
	return (dst_len + src_len);
}
