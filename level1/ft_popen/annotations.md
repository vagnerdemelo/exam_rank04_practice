## Descritivo de funcionamento de funções chaves para o exercicio
- `pipe(int[2])` - recebe um array de dois inteiros e cria um canal comunicação com o kernel. O pipe retorna um `FD` de escrita(`FD[1]`) e um de leitura (`FD[0]`)
- `fork()` - cria um processo filho do programa a partir de onde ele foi chamado no código.
- `dup2(fd, 1)`- permite redirecionar para onde será o input ou output. Podemos apontar o input padrão (`0` ou `STDIN_FILENO`), o output padrão (`1` ou `STDOUT_FILENO`) ou a saída de erros (`2` ou `STDERR_FILENO`) para um arquivo, por exemplo.
- `execvp(const char *file, char *const argv[])` - recebe o nome ou caminho do programa que vamos executar, `ls`, `cat`ou `grep`, por exemplo, e um array contendo os argumentos que serão passados ao programa, terminados por `NULL`. Ex:
	```
	char *args[] = {"ls", "-l", NULL}; // outra opção valida é: execvp("ls", (char *const []){"ls", "-l", NULL});

	execvp("ls", args);
	```
	Isso executa o equivalente ao comando `ls -l`.

	Se `execvp()` funcionar, ela não retorna ao código original. Se falhar, retorna `-1`.
