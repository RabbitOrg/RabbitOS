#include "stdio.h"

int main(int argc, char * argv[])
{
	if(argc == 1) {
		printf("please input the filename.\n");
	}

	if (unlink(argv[1]) == 0)
		printf("File removed: %s\n", argv[1]);
	else
		printf("Failed to remove file: %s\n", argv[1]);

	return 0;
}
