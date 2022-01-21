/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeocho <yeocho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 15:26:02 by yeocho            #+#    #+#             */
/*   Updated: 2022/01/21 12:36:58 by yeocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	num_length(long long n)
{
	int	length;

	length = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		length++;
	}
	while (n > 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char		*str;
	long long	nbr;
	int			length;

	nbr = n;
	length = num_length(nbr);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (!str)
		return (NULL);
	str[length--] = '\0';
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		str[length--] = '0' + (nbr % 10);
		nbr /= 10;
	}
	return (str);
}
