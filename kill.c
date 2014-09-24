#include  <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <bits/signum.h>

int main(int argc,char **argv)
{
	int i;
	if (argc != 3) {
		printf("my_kill - usage : %s <pid> <signal>\n",argv[0]);
		exit(1);
	}

	if ((i = kill(atoi(argv[1]),atoi(argv[2]))) == -1) {
			printf("error - cannot kill\n");
			exit(1);
	}
}
