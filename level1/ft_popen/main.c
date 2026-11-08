#include "fcntl.h"
#include <unistd.h>

int	main(void)
{
	int fd = open("app.log", O_WRONLY | O_CREAT | O_APPEND, 0644);

	dup2(fd, 1);

	while(1)
	{
		write(1, "Hello Vagner\n", 13);
		sleep(2);
	}
	return (0);
}
