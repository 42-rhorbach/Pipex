/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 13:34:08 by rhorbach      #+#    #+#                 */
/*   Updated: 2022/11/11 13:00:21 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned long	counter;
	unsigned char	b;
	unsigned char	*str;

	b = c;
	str = ptr;
	counter = 0;
	while (counter != n)
	{
		str[counter] = c;
		counter++;
	}
	return (str);
}
