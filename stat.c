#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
int main(int argc,char **argv)
{
	struct stat t;
	if (argc != 2) {
		printf("my_stat - usage : %s <file>\n",argv[0]);
		exit(1);
	}
	
	if ((stat(argv[1],&t)) == -1) {
		perror("stat");
		exit(1);
	}
 	printf("filename: %s\n", argv[1]);
	printf(" device: %lld\n",                      (long long int) t.st_dev);
	printf(" inode: %ld\n",                        (long int)t.st_ino);
	printf(" protection: %o\n",                    (unsigned int)t.st_mode);	
	printf(" number of hard links: %d\n",          (int)t.st_nlink);
	printf(" user ID of owner: %d\n",              (int) t.st_uid);
	printf(" group ID of owner: %d\n",             (int) t.st_gid);
	printf(" device type (if inode device): %lld\n",(long long int)t.st_rdev);
	printf(" total size, in bytes: %ld\n",          (long int)t.st_size);
	printf(" blocksize for filesystem I/O: %ld\n",  (long int)t.st_blksize);
	printf(" number of blocks allocated: %ld\n",    (long int)t.st_blocks);
	printf(" time of last access: %ld : %s",        (long int)t.st_atime, ctime(&t.st_atime));
	printf(" time of last modification: %ld : %s",  (long int)t.st_mtime, ctime(&t.st_mtime));
	printf(" time of last change: %ld : %s",        (long int)t.st_ctime, ctime(&t.st_ctime));


	return 0;
}

	

