/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/06 11:12:27 by rhorbach      #+#    #+#                 */
/*   Updated: 2022/10/06 11:32:10 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>

// int	main()
// {
// 	char c = '*';
// 	char g = '*';

// 	printf("%i\n", ft_toupper(c));
// 	printf("%i\n", toupper(g));
// }
