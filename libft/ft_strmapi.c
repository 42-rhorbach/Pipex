/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/24 13:50:28 by rhorbach      #+#    #+#                 */
/*   Updated: 2022/10/26 17:14:37 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (ptr != NULL)
	{
		while (s[i] != '\0')
		{
			ptr[i] = (*f)(i, s[i]);
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}
