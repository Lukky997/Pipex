/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:50:44 by lgoras            #+#    #+#             */
/*   Updated: 2025/05/16 16:24:25 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_1(char **argv, int *p_fd, char **envp)
{
	int	fd_infile;

	fd_infile = open(argv[1], O_RDONLY, 0777);
	if (fd_infile == -1)
		exit(0);
	dup2(fd_infile, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	close(p_fd[1]);
	execve(get_path(&argv[2][0], envp), ft_split(argv[2], ' '), envp);
}

void	child_2(char **argv, int *p_fd, char **envp)
{
	int	fd_oufile;

	fd_oufile = open(argv[4], O_RDONLY, 0777);
	if (fd_oufile == -1)
		exit(0);
	dup2(p_fd[0], 0);
	dup2(fd_oufile, 0);
	close(p_fd[0]);
	close(p_fd[1]);
	execve(get_path(&argv[4][0], envp), ft_split(argv[4], ' '), envp);
}

int	main(int argc, char **argv, char **env)
{
	int		p_fd[2];
	pid_t	pid;

	if (argc != 5)
		exit_error(1,
			"\033[1m⚠️  \033[1;33mUsage : \033[36m\"./pipex \033[3minfile cmd1 cmd2 outfile\033[0;36m\"\033[0m\n");
	if (pipe(p_fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == -1)
		exit(-1);
	if (!pid)
		child_1(argv, p_fd, env);
	child_2(argv, p_fd, env);
	return (0);
}
