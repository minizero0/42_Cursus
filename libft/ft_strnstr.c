/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeocho <yeocho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:44:48 by yeocho            #+#    #+#             */
/*   Updated: 2021/11/26 17:54:25 by yeocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	size;
	size_t	haystack_len;
	size_t	needle_len;

	if (*needle == '\0')
		return ((char *)haystack);
	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(haystack);
	if (haystack_len < needle_len || len < needle_len)
		return (NULL);
	if (haystack_len > len)
		size = len;
	else
		size = haystack_len;
	while (size >= needle_len)
	{
		if (ft_memcmp(haystack, needle, needlee_len) == 0)
			return ((char *)haystack);
		haystack++;
		size--;
	}
	return (NULL);
}
