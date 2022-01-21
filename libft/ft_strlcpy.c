/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeocho <yeocho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:59:38 by yeocho            #+#    #+#             */
/*   Updated: 2022/01/21 10:59:07 by yeocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	length;

	if (!dst)
		return (0);
	index = 0;
	length = ft_strlen(src);
	if (dstsize != 0)
	{
		while (src[index] && index < (dstsize - 1))
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	return (length);
}
