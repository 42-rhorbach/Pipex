/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 13:34:08 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/04/19 16:56:14 by rhorbach      ########   odam.nl         */
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
		str[counter] = b;
		counter++;
	}
	return (str);
}
