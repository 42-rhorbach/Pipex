/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/15 12:00:02 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/04/19 16:55:52 by rhorbach      ########   odam.nl         */
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
# include <sys/wait.h>
# include "libft.h"

# define READ 0
# define WRITE 1

typedef enum e_error
{
	OK,
	E_ARGC,
	E_ARGS,
	E_SYS,
	E_CMD_NOT_FOUND,
	E_ENVP
}	t_error;

t_error	set_error(t_error err);
t_error	get_error(void);
void	print_error(t_error err);
t_error	get_paths(char **envp, char ***paths);
char	*getenvvar(char *varname, char **envp);
t_error	find_in_paths(char *cmd, char **paths, char	**cmd_path);
void	free_args(char *args[]);
t_error	exec_command(char *cmd, char *envp[]);
t_error	first_child(int pipefd[], char *input_file, char *cmd, char *envp[]);
t_error	last_child(int pipefd[], char *output_file, char *cmd, char *envp[]);
t_error	create_children(int pipefd[2], char **argv, char **envp, int *exitcode);

#endif
