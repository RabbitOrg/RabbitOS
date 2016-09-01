#include "stdio.h"
#include "../include/string.h"

int main(int argc, char * argv[])
{
	int i = -1;
	printf("I want a ls.\n");
	char bufr[1024];
	memset(bufr, 0, 1024);
	i = list("\\", bufr);
	//assert(i);
	printf("return %d\ncontent: %s \n", i, bufr);
	/*printf("2");
	printf("%s", p);
	while(p) {
		printf("4");
		while(p[0] != '|')
			printf("%c", p);
		printf(" ");
	}*/

	printf("\n");
	return 0;
}
