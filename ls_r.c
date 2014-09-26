#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>




int compare (const void *a,const void *b)
{
	const char *a1 = *(char **)a;
	const char *b1 = *(char **)b;
	return strcmp(a1,b1);
}


void pwd(char cwd[]);

void lookin(char *a[],int i);

void listfolder(char *path);

int main(int argc,char **argv)
{

	listfolder(".");
	return 0;
}

void pwd(char cwd[])
{
	char ar[100];
	getcwd(ar,sizeof(ar));
	strcat(ar,"/");
	strcpy(cwd,ar);
}

void listfolder(char *path)
{
	DIR *o;
	struct dirent *p;
	struct stat t;
	char cwd[100];
	char *argar[100];
	int i = 0;
	int j = 0;
	if ((o = opendir(path)) != NULL) {
		while ((p = readdir(o)) != NULL) {
				if(strcmp(p->d_name,".") != 0 && strcmp(p->d_name,"..") != 0 && strcmp(p->d_name,".git") != 0) 
					argar[i++] = p->d_name;
		}
		argar[i] = 0;
	}
	qsort(argar,i,sizeof(char *),compare);
	while (j < i)
		printf("%s  ",argar[j++]);

	printf("\n\n");
	lookin(argar, i);
}


void lookin(char *argar[],int j)
{
	int i = 0;
	struct stat t;
	char cwd[100];
	char *m;
	while (i < j) {
		if (stat(argar[i],&t) == 0) {
			if (t.st_mode & S_IFDIR) {
				pwd(cwd);
				m = strcat(cwd,argar[i]);
				printf("%s",cwd);
				chdir(m);
				printf("\n");
				listfolder(m);
				chdir("..");
				printf("\n");
			}
		}
		i++;
	}
}




