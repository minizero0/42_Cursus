/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeocho <yeocho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 13:34:29 by yeocho            #+#    #+#             */
/*   Updated: 2022/01/04 13:35:04 by yeocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *ret;
    size_t  len1;

    if (!s)
        return (NULL);
    if ((unsigned int)ft_strlen(s) < start)
        return (ft_strdup(""));
    len1 = ft_strlen(s + start);
    if (len1 < len)
        len = len1;
    ret = (char *)malloc(sizeof(char) * (len + 1));
    if (!ret)
        return (NULL);
    ft_strlcpy(ret, s + start, len + 1);
    return (ret);
}
