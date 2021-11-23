/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeocho <yeocho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:05:05 by yeocho            #+#    #+#             */
/*   Updated: 2021/11/22 16:21:09 by yeocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (*s1 && *s2 && index < n)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
		index++;
	}
	if (index == n)
		return (0);
	else
		return (*s1 - *s2);
}
