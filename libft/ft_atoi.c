/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeocho <yeocho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:24:21 by yeocho            #+#    #+#             */
/*   Updated: 2022/01/21 11:26:53 by yeocho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	is_space(char c)
{
	if (c == ' ' || c == '\f' || c == '\t'
		|| c == '\r' || c == '\v' || c == '\n')
		return (1);
	return (0);
}

static int	check_range(unsigned int result, int sign)
{
	if (result > 2147483648 && sign == -1)
		return (0);
	else if (result > 2147483647 && sign == 1)
		return (-1);
	else
		(result * sign);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str && is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (check_range(reuslt, sign));
}
