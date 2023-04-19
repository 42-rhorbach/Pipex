/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rhorbach <rhorbach@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/17 10:46:03 by rhorbach      #+#    #+#                 */
/*   Updated: 2023/04/19 16:11:16 by rhorbach      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

t_error	get_paths(char **envp, char ***paths)
{
	char	*path;

	path = getenvvar("PATH", envp);
	if (path == NULL)
		return (set_error(E_ENVP));
	*paths = ft_split(path, ':');
	if (paths == NULL)
		return (set_error(E_SYS));
	return (OK);
}

char	*getenvvar(char *varname, char **envp)
{
	int	i;
	int	len;

	len = ft_strlen(varname);
	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(varname, envp[i], len) == 0)
		{
			if (envp[i][len] == '=')
				return (&envp[i][len + 1]);
		}
		i++;
	}
	return (NULL);
}

t_error	find_in_paths(char *cmd, char **paths, char	**cmd_path)
{
	int		i;
	char	*slash_cmd;

	i = 0;
	slash_cmd = ft_strjoin("/", cmd);
	if (slash_cmd == NULL)
		return (set_error(E_SYS));
	while (paths[i] != NULL)
	{
		*cmd_path = ft_strjoin(paths[i], slash_cmd);
		if (*cmd_path == NULL)
		{
			free(slash_cmd);
			return (set_error(E_SYS));
		}
		if (access(*cmd_path, X_OK) == 0)
		{
			free(slash_cmd);
			return (OK);
		}
		free(*cmd_path);
		i++;
	}
	free(slash_cmd);
	return (set_error(E_CMD_NOT_FOUND));
}

void	free_args(char *args[])
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		free(args[i]);
		i++;
	}
	free(args);
}
