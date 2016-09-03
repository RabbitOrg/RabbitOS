#include "stdio.h"
#include "../include/sys/fs.h"

int main(int argc, char * argv[])
{
	/* create */
	int fd = open(argv[1], O_CREAT | O_RDWR);
	assert(fd != -1);
	printf("File created: %s (fd %d)\n", argv[1], fd);

	close(fd);

	return 0;
}
