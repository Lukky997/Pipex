/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:05:02 by lgoras            #+#    #+#             */
/*   Updated: 2025/05/17 14:55:53 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exit_error(int nb_exit)
{
	if (nb_exit == 1)
		ft_putstr_fd("\033[0;91m\033[1m⚠️  Usage: \"./pipex infile "
			"cmd1 cmd2 outfile\"\n\033[0m", 2);
	else if (nb_exit == 2)
		ft_putstr_fd("\033[0;95m\033[1m❌ Command not found.\n\033[0m", 2);
	else if (nb_exit == 3)
		ft_putstr_fd("\033[0;95m\033[1m⚠️  Command NULL detected.\n\033[0m", 2);
	else if (nb_exit == 4)
		ft_putstr_fd("\033[0;91m\033[1m🚫 Input file does not exist.\n\033[0m",
			2);
	else if(nb_exit == 5)
		ft_putstr_fd("\033[0;91m\033[1m⚠️  Environment is empty\n\033[0m", 2);
	else
		ft_putstr_fd("\033[0;93m\033[1m❗ Unknown error occurred.\n\033[0m", 2);
	exit(EXIT_FAILURE);
}

static char	**free_tab(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

static char	*get_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

static char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*full_path;
	char	*temp;
	char	*env_path;

	env_path = get_env(envp);
	paths = ft_split(env_path, ':');
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		full_path = ft_strjoin(temp, cmd);
		free(temp);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			free_tab(paths);
			return (full_path);
		}
		free(full_path);
		i++;
	}
	free_tab(paths);
	return (NULL);
}

void	exec(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0] || cmd[0][0] == '\0')
	{
		free_tab(cmd);
		exit_error(3);
	}
	if (access(cmd[0], X_OK) == 0)
		execve(cmd[0], cmd, envp);
	path = get_path(cmd[0], envp);
	if (!path)
	{
		free_tab(cmd);
		exit_error(2);
	}
	execve(path, cmd, envp);
	free(path);
	free_tab(cmd);
	exit_error(2);
}
