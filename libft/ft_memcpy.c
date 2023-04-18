/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/05 16:57:25 by rhorbach      #+#    #+#                 */
/*   Updated: 2022/11/11 12:59:09 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *pdst, const void *psrc, size_t n)
{
	size_t		index;
	char		*dst;
	const char	*src;

	index = 0;
	dst = pdst;
	src = psrc;
	if (dst != NULL || src != NULL)
	{
		while (index != n)
		{
			dst[index] = src[index];
			index++;
		}
	}
	return (dst);
}
