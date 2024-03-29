/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 14:57:07 by rhorbach      #+#    #+#                 */
/*   Updated: 2022/11/11 12:46:07 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int arg)
{
	return ((arg >= 'A' && arg <= 'Z') || (arg >= 'a' && arg <= 'z'));
}
