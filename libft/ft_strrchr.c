/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/07 12:27:32 by rhorbach      #+#    #+#                 */
/*   Updated: 2022/11/11 13:06:52 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char		a;
	char		*temp;
	char		*str;
	int			i;

	temp = NULL;
	str = (char *)s;
	a = c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == a)
			temp = &str[i];
		i++;
	}
	if (a == '\0')
		temp = &str[i];
	return (temp);
}
