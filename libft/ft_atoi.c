/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 12:02:40 by rhorbach      #+#    #+#                 */
/*   Updated: 2022/11/11 12:44:11 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_isspace(int c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	ft_atoi(const char *str)
{
	int	i;
	int	c;
	int	sign;

	i = 0;
	c = 0;
	sign = -1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = 1;
		i++;
	}
	while (ft_isdigit((int)str[i]) == 1)
	{
		c = ((c * 10) - (str[i] - '0'));
		i++;
	}
	return (c * sign);
}
