#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(int argc, char **args)
{
	int fd_test1;
	int fd_test2;
	int ret;
	char *line;

	fd_test1 = open(args[1], O_RDONLY);
	fd_test2 = open(args[2], O_RDONLY);

	if (fd_test1 < 0 || fd_test2 < 0)
	{
		printf("error when opening file\n");
		return 1;
	}

	get_next_line(fd_test1, &line);
	printf("test1: <%s>\n", line);

	get_next_line(fd_test2, &line);
	printf("\t\t\t\ttest2: <%s>\n", line);

	get_next_line(fd_test1, &line);
	printf("test1: <%s>\n", line);

	get_next_line(fd_test1, &line);
	printf("test1: <%s>\n", line);

	get_next_line(fd_test2, &line);
	printf("\t\t\t\ttest2: <%s>\n", line);

	get_next_line(fd_test2, &line);
	printf("\t\t\t\ttest2: <%s>\n", line);

	get_next_line(fd_test2, &line);
	printf("\t\t\t\ttest2: <%s>\n", line);

	get_next_line(fd_test1, &line);
	printf("test1: <%s>\n", line);

	free(line);

	close(fd_test1);
	close(fd_test2);
	//  sleep(5);
	 return 0;
}
