/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeocho <yeocho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:52:32 by yeocho            #+#    #+#             */
/*   Updated: 2022/01/21 11:39:29 by yeocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ret;
	int		index;

	index = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!ret)
		return (NULL);
	while (s1[index])
	{
		ret[index] = s1[index];
		index++;
	}
	ret[index] = '\0';
	return (ret);
}
