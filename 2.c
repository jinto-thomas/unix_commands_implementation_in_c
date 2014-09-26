#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
#include <limits.h>
#include <string.h>
#include <bits/signum.h>
#include <assert.h>

int i;

char *tab(char b[],int n);
char *leaf(char a[],int k);
void printeverything(char *);
void walkin(char *);
void pwd(char a[]);

int main(int argc,char **argv)
{
	char name[100];
	pwd(name);
	printeverything(name);
	
	return 0;


}

void pwd(char cwd[])
{
	char ar[100];
	getcwd(ar,sizeof(ar));
	strcat(ar,"/");
	strcpy(cwd,ar);
}


void printeverything(char *path) {
	
	char name[100],name2[100];
	char a[20];
	char b[20];
	DIR *o;
	struct dirent *p;
	struct stat t;
	char *m;
	
	if ((o = opendir(path)) != NULL) {	
		while ((p = (readdir(o))) != NULL) {
			if (stat(p->d_name,&t) == 0 ) {
				if (!(t.st_mode & S_IFDIR)) {
					printf("%s|%s%s\n",tab(b,i),leaf(a,i),p->d_name);
				}	
				else {
					if (strcmp(p->d_name,".") == 0 || strcmp(p->d_name,"..") == 0 || strcmp(p->d_name,".git") == 0)
						continue;
					printf("%s[#%s]\n",tab(b,i),p->d_name);
					pwd(name2);
					m = strcat(name2,p->d_name);
					chdir(m);
					i++;
					printeverything(m);
					chdir("..");
					i--;

				}
			}
		}
		closedir(o);
		
	}
}


char *leaf(char a[],int k)
{
	int j = 0;
	while (j <= 2*k) {
		a[j++] = '-';
		a[j++] = ' ';
	}
	a[j] = '\0';

	return a;
}

char *tab(char b[],int n)
{
	int j = 0;
	while (j <= n)
		b[j++] = '\t';
	b[j] = 0;
	return b;
}
