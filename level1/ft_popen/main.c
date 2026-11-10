
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int ft_popen(const char *file, char *const argv[], char type);
int ft_popen2(const char *file, char *const argv[], char type);

int main(void)
{
    int fd;
    char buffer[1024];
    ssize_t bytes;

    // TESTE 1: Modo leitura ('r')
    printf("=== TESTE DE LEITURA ===\n");
    fflush(stdout);

    char *args_ls[] = {"ls", "-l", NULL};

    fd = ft_popen2("ls", args_ls, 'r');
    if (fd == -1)
        return (1);

    while ((bytes = read(fd, buffer, sizeof(buffer))) > 0)
        write(STDOUT_FILENO, buffer, bytes);

    close(fd);
    wait(NULL);

    // TESTE 2: Modo escrita ('w')
    printf("\n=== TESTE DE ESCRITA ===\n");
    fflush(stdout);

    char *args_cat[] = {"cat", NULL};

    fd = ft_popen2("cat", args_cat, 'w');
    if (fd == -1)
        return (1);

    write(fd, "Hello from parent!\n", 19);

    close(fd);
    wait(NULL);

    return (0);
}
