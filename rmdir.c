#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
	int st;
	if (argc < 2) {
		printf("usage:\n");
		exit(1);
	}
	while (--argc) {
		if ((st = rmdir(*++argv)) == -1)
			printf("directory not empty!\n");
	}
	return 0;
}
