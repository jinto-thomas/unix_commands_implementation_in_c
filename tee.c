#define _GNU_SOURCE
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#define SIZE 1024
#include <limits.h>
#include <string.h>

int main(int argc,char **argv)
{
	int fd, len, n;
	char buf[SIZE];

	if (argc != 2) {
		fprintf(stderr,"my_tee - usage : %s <file>\n",argv[0]);
		exit(EXIT_FAILURE);
	}
	
	fd = open(argv[1],O_RDWR | O_CREAT | O_TRUNC,0644);

	while ((n = read(0,buf,SIZE)) > 0) {
		write(1,buf,n);
		write(fd,buf,n);
	}
	close(fd);
	return 0;


}

