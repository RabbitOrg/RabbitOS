#include "stdio.h"
#include "../include/sys/fs.h"

int main(int argc, char * argv[])
{
	int i = -1;
	char bufr[1024];
	memset(bufr, 0, 1024);
	i = list("\\", bufr);

	if(i != 0) {
		printf("Something wrong!");
		return -1;
	}

	for(i = 0; bufr[i] != 0; i++) {
		if(bufr[i] != '|')
			printf("%c", bufr[i]);
		else
			printf(" ");
	}


	printf("\n");
	return 0;
}
