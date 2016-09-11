#include "stdio.h"

int main(int argc, char * argv[])
{
	int fd;
	
	if(argc == 1) {
		printf("touch: please input the filename.\n");
		return 0;
	}

	// create 
	fd = open(argv[1], O_CREAT | O_RDWR);
	if(fd == -1) {
		printf("touch: %s is already existed.\n", argv[1]);
		return 0;
	}
	printf("File created: %s (fd %d)\n", argv[1], fd);

	close(fd);

	return 0;
}
