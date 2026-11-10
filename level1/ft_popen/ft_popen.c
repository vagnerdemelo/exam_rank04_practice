#include "fcntl.h"
#include <unistd.h>

int ft_popen(const char *file, char *const argv[], char type)
{
	if (!file || !argv || type != 'w' && type != 'r')
		return -1;

	int fd[2];
	if (pipe(fd) == -1)
		return -1;

	pid_t pid = fork();
	if (pid == -1)
	{
		close(fd[0]);
		close(fd[1]);
		return -1;
	}

	if (pid == 0) // processo filho
	{
		if (type == 'r')
		{
			if (dup2(fd[1], STDOUT_FILENO) == -1)
				exit(1);
		}
		else
			if (dup2(fd[0], STDIN_FILENO) == -1)
				exit(1);

		close(fd[0]);
		close(fd[1]);

		if (execvp(file, argv) == -1)
			exit(1);
	}
	else if (pid > 0 ) // processo pai
	{
		if (type == 'r')
		{
			close(fd[1]); // fecha o fd de escrita e retorna o de leitura
			return fd[0];
		}
		else
		{
			close(fd[0]); // fecha o fd de leitura e retorna o de escrita
			return fd[1];
		}
	}
}
