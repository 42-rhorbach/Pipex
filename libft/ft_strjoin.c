/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/18 13:12:40 by rhorbach      #+#    #+#                 */
/*   Updated: 2022/10/26 17:14:20 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*nstr;
	size_t	len1;
	size_t	len2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	len1 = (ft_strlen(str1) + 1);
	len2 = (ft_strlen(str2));
	nstr = malloc((len1 + len2) * sizeof(char));
	if (nstr != NULL)
	{
		ft_strlcpy(nstr, str1, len1);
		ft_strlcat(nstr, str2, (len1 + len2));
	}
	return (nstr);
}
