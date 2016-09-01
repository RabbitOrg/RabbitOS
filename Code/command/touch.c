#include "stdio.h"
#include "../include/sys/fs.h"

int main(int argc, char * argv[])
{
//	int i;
//	for (i = 1; i < argc; i++)
//		printf("%s%s", i == 1 ? "" : " ", argv[i]);



	/* create */
	int fd = open(argv[1], O_CREAT | O_RDWR);
	assert(fd != -1);
	printf("File created: %s (fd %d)\n", argv[1], fd);

	return 0;
}
