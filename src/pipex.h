/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 12:00:02 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/03/16 15:07:22 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>

typedef enum e_error
{
	OK,
	E_ARGC,
	E_ARGS,
	E_SYS,
	E_CMD_NOT_FOUND
	// E_PIPE,
	// E_FORK,
	// E_DUP2,
	// E_EXECVE,
	// E_ACCESS,
	// E_OPEN,
	// E_WAITPID
}	t_error;

t_error	set_error(t_error err);
t_error	get_error(void);

#endif
