/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 18:50:44 by lgoras            #+#    #+#             */
/*   Updated: 2025/05/17 14:56:04 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_1(char **argv, int *p_fd, char **envp)
{
	int	fd_infile;

	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile == -1)
	{
		close(p_fd[0]);
		close(p_fd[1]);
		exit_error(4);
	}
	dup2(fd_infile, STDIN_FILENO);
	dup2(p_fd[1], STDOUT_FILENO);
	close(fd_infile);
	close(p_fd[0]);
	close(p_fd[1]);
	exec(argv[2], envp);
}

void	child_2(char **argv, int *p_fd, char **envp)
{
	int	fd_outfile;

	fd_outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_outfile == -1)
	{
		close(p_fd[0]);
		close(p_fd[1]);
		exit_error(1);
	}
	dup2(p_fd[0], STDIN_FILENO);
	dup2(fd_outfile, STDOUT_FILENO);
	close(fd_outfile);
	close(p_fd[0]);
	close(p_fd[1]);
	exec(argv[3], envp);
}

static void	check_args_and_infile(int argc, char *infile)
{
	int	fd;

	if (argc != 5)
		exit_error(1);
	fd = open(infile, O_RDONLY);
	if (fd < 0)
		exit_error(4);
	close(fd);
}

static void	create_processes(char **argv, char **envp, int *p_fd)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 == -1)
		exit_error(1);
	if (pid1 == 0)
		child_1(argv, p_fd, envp);
	pid2 = fork();
	if (pid2 == -1)
		exit_error(1);
	if (pid2 == 0)
		child_2(argv, p_fd, envp);
}

int	main(int argc, char **argv, char **env)
{
	int	p_fd[2];

	if (!env || !env[0])
		exit_error(5);
	check_args_and_infile(argc, argv[1]);
	if (pipe(p_fd) == -1)
		exit_error(1);
	create_processes(argv, env, p_fd);
	close(p_fd[0]);
	close(p_fd[1]);
	waitpid(-1, NULL, 0);
	waitpid(-1, NULL, 0);
	return (0);
}
