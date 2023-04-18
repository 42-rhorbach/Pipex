/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/16 12:45:11 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/04/18 13:13:11 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static t_error	*get_error_ptr(void)
{
	static t_error	err_ptr = OK;

	return (&err_ptr);
}

t_error	set_error(t_error err)
{
	t_error	*err_ptr;

	err_ptr = get_error_ptr();
	*err_ptr = err;
	return (*err_ptr);
}

t_error	get_error(void)
{
	t_error	*err_ptr;

	err_ptr = get_error_ptr();
	return (*err_ptr);
}

void	print_error(t_error err)
{
	static const char	*error_table[] = {
	[E_ARGC] = "Too many/few arguments.",
	[E_ARGS] = "Could not allocate memory for argv.",
	[E_CMD_NOT_FOUND] = "Command not found.",
	[E_ENVP] = "Path not found."
	};

	if (err == E_SYS)
		perror("pipex");
	else
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putendl_fd((char *)error_table[err], STDERR_FILENO);
	}
}
