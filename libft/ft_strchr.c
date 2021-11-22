/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeocho <yeocho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:41:15 by yeocho            #+#    #+#             */
/*   Updated: 2021/11/22 15:51:40 by yeocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*index;

	index = s;
	while (*s)
	{
		s++;
	}
	while (*s >= *index)
	{
		if (*s == (unsigned char *)c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}
