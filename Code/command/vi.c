#include "stdio.h"
#include "../include/string.h"

int main(int argc, char * argv[])
{
	int fd, n;
	char bufw[1024];
	memset(bufw, 0, 1024);

	if(argc == 1) {
		printf("vi: please input the filename.\n");
		return -1;
	}

	// open
	fd = open(argv[1], O_RDWR);
	if(fd == -1) {
		printf("vi: %s: No such file or directory\n", argv[1]);
		return -1;
	}

    int end = read(0, bufw, 1024);
    bufw[end] = 0;

	n = write(fd, bufw, strlen(bufw));
	close(fd);

	printf("File saved: %s \n", argv[1]);

	return 0;
}
