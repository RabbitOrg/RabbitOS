#include "stdio.h"

int main(int argc, char * argv[])
{
	int fd, _fd;
	char bufr[1024];
	memset(bufr, 0, 1024);
	
	if(argc <= 2) {
		printf("mv: please input the the source and destination filenames.\n");
		return 0;
	}

	// create 
	fd = open(argv[1], O_RDWR);
	if(fd == -1) {
		printf("mv: %s: No such file or directory\n", argv[1]);
		return 0;
	}
	int end = read(fd, bufr, 1024);
	close(fd);

	_fd = open(argv[2], O_CREAT | O_RDWR);
	if(_fd == -1) {
	}else {
		char temp[10];
		temp[0] = 0;
		write(_fd, temp, 1);
		close(_fd);
	}

	_fd = open(argv[2], O_RDWR);
	write(_fd, bufr, end + 1);
	close(_fd);

	unlink(argv[1]);

	return 0;
}
