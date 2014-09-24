#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <limits.h>

void printeverything(void);

int main(int argc,char **argv)
{

	printeverything();
	return 0;


}
void printeverything(void) {
	DIR *o;
	struct dirent *p;
	struct stat t;
	o = opendir(".");
	while ((p = (readdir(o))) != NULL) {
		if (stat(p->d_name,&t) == 0) {
			if (t.st_mode & S_IFDIR) {

				printf("FOLDER :%s\n",p->d_name);
//				printeverything();
//				closedir(o);
			}
			else
				printf("FILE : %s\n",p->d_name);
		}
	//	closedir(o);
	}
	closedir(o);
}

