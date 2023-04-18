/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/10 12:21:25 by rhorbach      #+#    #+#                 */
/*   Updated: 2022/11/11 12:59:43 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *pdst, const void *psrc, size_t len)
{
	size_t		index;
	char		*dst;
	const char	*src;

	index = len;
	dst = pdst;
	src = psrc;
	if (src > dst)
		ft_memcpy(dst, src, len);
	if (src < dst)
	{
		while (index > 0)
		{
			index--;
			dst[index] = src[index];
		}
	}
	return (dst);
}
