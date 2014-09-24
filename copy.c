#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#define SIZE 1024

int main(int argc,char *argv[])
{
	int fd,fd2,n;
	char buf[SIZE];
	if (argc != 3) {
		printf("my_cp - usage : my_cp <source_file> <dest_file>\n");
		exit(1);
	}
	if ((fd = open(argv[1],O_RDONLY)) == -1) {
		printf("cannot open source %s\n",argv[1]);
		exit(1);
	}
	if ((fd2 = open(argv[2],O_RDWR | O_CREAT | O_TRUNC,0644)) == -1) {
		printf("cannot open dest %s\n",argv[2]);
		exit(1);
	}
	while ((n = read(fd,buf,SIZE)) > 0) {
		if (write (fd2,buf,n) != n) {
			printf("my_cp write erron\n");
			exit(1);
		}
	}
	return 0;
}

