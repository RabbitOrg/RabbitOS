#include "stdio.h"

int main(int argc, char * argv[])
{
	const char bufw[] = "Welcome!\nThis is Rabbit OS.\nThis operating system uses Orange's OS kernel and was modified by tsengkasing, rabbit and zayy in order to finish the project of course. :)";
	int fd, n;
	const int rd_bytes = 10;
	char bufr[rd_bytes];
	

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

	n = write(fd, bufw, strlen(bufw));

	close(fd);

	return 0;
}
