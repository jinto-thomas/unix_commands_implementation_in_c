#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

int main(int argc,char *argv[])
{

	while (--argc)
		printf("%s ",*++argv);
	printf("\n");
}
