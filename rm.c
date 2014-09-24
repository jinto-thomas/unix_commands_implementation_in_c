#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
	int st;
	if (argc < 2 ) {
		printf("my_rm - usage : %s <file or directory>\n",argv[0]);
		exit(1);
	}
	while (--argc) {
		if ((st = remove(*++argv)) == -1)
			printf("cannot remove %s\n",*argv);
	}
	return 0;
}
