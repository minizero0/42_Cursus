/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeocho <yeocho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:24:21 by yeocho            #+#    #+#             */
/*   Updated: 2021/12/22 17:34:29 by yeocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\t'
		|| c == '\r' || c == '\v')
		return (1);
	return (0);
}

int	check_range(unsigned int result, int minus)
{
	if (result > 2147483648 && minus == -1)
		return (0);
	else if (result > 2147483647 && minus == 1)
		return (-1);
	else
		(result * minus);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	minus;

	result = 0;
	minus = 1;
	while (*str && is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (check_range(reuslt, minus));
}
