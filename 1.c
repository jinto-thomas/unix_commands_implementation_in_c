#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>
#include <bits/signum.h>
#include <assert.h>

void printeverything(char *);
void walkin(char *);
char *pwd(void);

int main(int argc,char **argv)
{
	char *name;
	name = pwd();
	printeverything(name);
	
	return 0;


}

char *pwd()
{
	char cwd[50];

	getcwd(cwd,sizeof(cwd));
	return strcat(cwd,"/");
}


void printeverything(char *path) {
	char name[100],name2[100];
	DIR *o;
	struct dirent *p;
	struct stat t;
	char *m;
	char *c;	
	char *d;
	int i;
	o = opendir(path);
	assert(o != NULL);
	
	for (i = 0; i < 100; i++){
		name[i] = '\0';
		name2[i] = '\0';
	}
	while ((p = (readdir(o))) != NULL) {
		if (stat(p->d_name,&t) == 0 ) {
			if (!(t.st_mode & S_IFDIR)) {
//				printf("\t%s\n",p->d_name);
			}	
			else {
				if (strcmp(p->d_name,".") == 0 || strcmp(p->d_name,"..") == 0 || strcmp(p->d_name,".git") == 0)
					continue;
				
				printf("[%s]\n",p->d_name);
//				printf("pwd :%s\n",pwd());
			//	c = p->d_name;
			//	d = pwd();
//				d = strcat(name,pwd());//,p->d_name);
//				m = strcat(name,p->d_name);
				strcat(name2,pwd());
				printf("%s\n",);
				for (i = 0; i < 100; i++){
					name[i] = '\0';
					name2[i] = '\0';
				}
//				walkin(m);
			}
		}
		
	}
	printf("GOT out From a Folder\n");
}

void walkin(char *path)
{
	DIR *o;
	struct dirent *p;

	o = opendir(path);
	printf("path=%s\n", path);
    assert(o!=NULL);
	while ((p = readdir(o)) != 0) {
		if (strcmp(p->d_name,".") == 0 || strcmp(p->d_name,"..") == 0 || strcmp(p->d_name,".git") == 0)
			continue;
		printf("\t\t#%s\n",p->d_name);
	}
	closedir(o);
	printf("------------------\n");
}
