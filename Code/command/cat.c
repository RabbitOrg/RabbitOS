#include "stdio.h"
#include "../include/sys/fs.h"

int main(int argc, char * argv[])
{
	const int rd_bytes = 1024;
	char bufr[rd_bytes];

	/* open */
	int fd = open(argv[1], O_RDWR);
	if(fd == -1) {
		printf("cat: %s: No such file or directory\n", argv[1]);
		return -1;
	}

	/* read */
	int n = read(fd, bufr, rd_bytes);
	bufr[n] = 0;
	printf("%s\n", bufr);

	close(fd);

	return 0;
}
