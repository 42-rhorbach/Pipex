/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   children.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 12:58:19 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/04/19 18:17:37 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_error	exec_command(char *cmd, char *envp[])
{
	char	**args;
	char	*cmd_path;

	args = ft_split(cmd, ' ');
	if (args == NULL)
		return (set_error(E_ARGS));
	if (args[0] == NULL)
	{
		free_args(args);
		return (set_error(E_ARGS));
	}
	if (ft_strchr(args[0], '/') == NULL)
	{
		if (get_command_path(envp, &cmd_path, args[0]) != OK)
		{
			free_args(args);
			return (set_error(E_ARGS));
		}
	}
	else
		cmd_path = args[0];
	execve(cmd_path, args, envp);
	free_args(args);
	return (set_error(E_SYS));
}

t_error	first_child(int pipefd[], char *input_file, char *cmd, char *envp[])
{
	int		filefd;

	if (access(input_file, F_OK) == 0 && access(input_file, R_OK) == -1)
		return (set_error(E_SYS));
	filefd = open(input_file, O_RDONLY);
	if (filefd == -1)
		return (set_error(E_SYS));
	close(pipefd[READ]);
	if (dup2(filefd, STDIN_FILENO) == -1)
	{
		close(filefd);
		return (set_error(E_SYS));
	}
	if (dup2(pipefd[WRITE], STDOUT_FILENO) == -1)
	{
		close(filefd);
		return (set_error(E_SYS));
	}
	if (exec_command(cmd, envp) != OK)
	{
		close(filefd);
		return (get_error());
	}
	return (OK);
}

t_error	last_child(int pipefd[], char *output_file, char *cmd, char *envp[])
{
	int		filefd;

	if (access(output_file, F_OK) == 0 && access(output_file, W_OK) == -1)
		return (set_error(E_SYS));
	filefd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (filefd == -1)
		return (set_error(E_SYS));
	if (dup2(pipefd[READ], STDIN_FILENO) == -1)
		return (set_error(E_SYS));
	if (dup2(filefd, STDOUT_FILENO) == -1)
		return (set_error(E_SYS));
	if (exec_command(cmd, envp) != OK)
	{
		close(filefd);
		return (get_error());
	}
	return (OK);
}

t_error	create_children(int pipefd[2], char **argv, char **envp, int *exitcode)
{
	pid_t	cpid[2];

	cpid[0] = fork();
	if (cpid[0] == -1)
		return (set_error(E_SYS));
	if (cpid[0] == 0)
		if (first_child(pipefd, argv[1], argv[2], envp) != OK)
			return (get_error());
	close(pipefd[WRITE]);
	cpid[1] = fork();
	if (cpid[1] == -1)
		return (set_error(E_SYS));
	if (cpid[1] == 0)
		if (last_child(pipefd, argv[4], argv[3], envp) != OK)
			return (get_error());
	close(pipefd[READ]);
	if (waitpid(cpid[1], exitcode, 0) == -1)
		return (set_error(E_SYS));
	if (waitpid(cpid[0], NULL, 0) == -1)
		return (set_error(E_SYS));
	return (OK);
}
