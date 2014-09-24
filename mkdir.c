#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
	int st;
	if (argc < 2) {
		printf("my_mkdir - usage : %s <directory_name>\n",argv[0]);
		exit(1);
	}
	while (--argc) {
		if ((st = mkdir(*++argv,S_IRWXU | S_IRWXG | S_IRWXO)) == -1) {
			printf("cannot creat %s\n",*argv);
			exit(1);
		}
	}
}

