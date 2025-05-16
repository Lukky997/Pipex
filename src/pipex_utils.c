/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:05:02 by lgoras            #+#    #+#             */
/*   Updated: 2025/05/16 16:16:52 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	exit_error(int nb_exit, char *str_error)
{
	if (nb_exit == 1)
		ft_putstr_fd(str_error, 2);
	exit(0);
}

char	**free_tab(char **s)
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

char	*get_env(char **envp)
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

char	*get_path(char *cmd, char **envp)
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
