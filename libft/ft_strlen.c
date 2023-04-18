/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/04 12:42:38 by rhorbach      #+#    #+#                 */
/*   Updated: 2022/10/26 17:21:05 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *ptr)
{
	size_t	counter;

	counter = 0;
	while (ptr[counter] != '\0')
		counter++;
	return (counter);
}
