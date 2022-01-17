/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeocho <yeocho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:57:18 by yeocho            #+#    #+#             */
/*   Updated: 2022/01/17 23:09:33 by yeocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char            *ret;
    unsigned char   length;
    unsigned char   index;

    if (!s || !f)
        return (0);
    length = ft_strlen(s);
    index = 0;
    ret = (char *)malloc(sizeof(char) * (length + 1));
    if (!ret)
        return (NULL);
    while (index < length)
    {
        ret[index] = f(index, s[index]);
        index++;
    }
    ret[index] = '\0';
    return (ret);
}