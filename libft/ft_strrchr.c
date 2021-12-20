/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeocho <yeocho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:56:52 by yeocho            #+#    #+#             */
/*   Updated: 2021/11/22 16:04:45 by yeocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*index;

	index = s;
	while (*s)
		s++;
	while (s >= index)
	{
		if (*s == (unsigned char *)c)
		{
			return (*s);
			s--;
		}
	}
	return (NULL);
}
