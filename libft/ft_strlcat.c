/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 17:00:19 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/04/19 16:56:42 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		len;

	len = 0;
	while (len != dstsize && dst[len] != '\0')
		len++;
	return (ft_strlcpy(&dst[len], src, dstsize - len) + len);
}
