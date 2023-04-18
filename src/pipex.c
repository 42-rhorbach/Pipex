/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/23 11:04:32 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/04/17 13:34:58 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_error	pipex(char **argv, char **envp, int *exitcode)
{
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		return (set_error(E_SYS));
	if (create_children(pipefd, argv, envp, exitcode) != OK)
		return (get_error());
	*exitcode = WEXITSTATUS(*exitcode);
	return (OK);
}

int	main(int argc, char **argv, char **envp)
{
	int	exitcode;

	if (argc != 5)
	{
		print_error(E_ARGC);
		return (EXIT_FAILURE);
	}
	if (pipex(argv, envp, &exitcode) != OK)
	{
		print_error(get_error());
		if (get_error() == E_CMD_NOT_FOUND)
			return (127);
		return (EXIT_FAILURE);
	}
	return (exitcode);
}
