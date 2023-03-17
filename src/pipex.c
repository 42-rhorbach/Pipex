/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/08 12:17:03 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/03/16 15:44:50 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

#define READ 0
#define WRITE 1

function(int	filefd, )
{

}

t_error	pipex(int argc, char **argv, char **envp)
{
	pid_t	cpid;
	pid_t	cpid2;
	int		pipefd[2];
	int		status;
	int		filefd;
	char 	**args;

	if (argc != 5)
		return (set_error(E_ARGC));
	if (pipe(pipefd) == -1)
		return (set_error(E_SYS));
	cpid = fork();
	if (cpid == -1)
		return (set_error(E_SYS));
	if (cpid == 0)
	{
		filefd = open(argv[1], O_RDONLY);
		if (filefd == -1)
			return (set_error(E_SYS));
		close(pipefd[READ]);
		if (dup2(filefd, STDIN_FILENO) == -1)
			return (set_error(E_SYS));
		if (dup2(pipefd[WRITE], STDOUT_FILENO) == -1)
			return (set_error(E_SYS));
		args = ft_split(argv[2], ' ');
		if (args == NULL)
			return (set_error(E_ARGS));
		execve(args[0], args, envp);
		close(filefd);
		return (set_error(E_CMD_NOT_FOUND));
	}
	close(pipefd[WRITE]);
	cpid2 = fork();
	if (cpid2 == -1)
		return (set_error(E_SYS));
	if (cpid2 == 0)
	{
		if (access(argv[4], F_OK) == 0 && access(argv[4], W_OK) == -1)
			return (set_error(E_SYS));
		filefd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (filefd == -1)
			return (set_error(E_SYS));
		if (dup2(pipefd[READ], STDIN_FILENO) == -1)
			return (set_error(E_SYS));
		if (dup2(filefd, STDOUT_FILENO) == -1)
			return (set_error(E_SYS));
		args = ft_split(argv[3], ' ');
		if (args == NULL)
			return (set_error(E_ARGS));
		execve(args[0], args, envp);
		close(filefd);
		return (set_error(E_CMD_NOT_FOUND));
	}
	close(pipefd[READ]);

	if (waitpid(cpid2, &status, 0) == -1)
		return (set_error(E_SYS));
	if (waitpid(cpid, &status, 0) == -1)
		return (set_error(E_SYS));

	return (OK);
// 	errno = EMFILE;
// 	perror("Could not pipe");
}

void	print_error(t_error err)
{
	static const char	*error_table[] = {
	[E_ARGC] = "Too many/few arguments.",
	[E_ARGS] = "Could not allocate memory for argv.",
	[E_CMD_NOT_FOUND] = "Command not found."
	};

	if (err == E_SYS)
		perror("pipex");
	else
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putendl_fd((char *)error_table[err], STDERR_FILENO);
	}
}

int	main(int argc, char **argv, char **envp)
{
	if (pipex(argc, argv, envp) != OK)
	{
		print_error(get_error());
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
