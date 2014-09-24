#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

int compare (const void *a,const void *b)
{
	const char *a1 = *(char **)a;
	const char *b1 = *(char **)b;
	return strcmp(a1,b1);
}


int main()
{
	DIR *o;

	struct dirent *d;

	char *argar[100];
	int i = 0;
	int n = 0;
	o = opendir(".");

	while ((d = readdir(o)) != NULL) {
			argar[i++] = d->d_name;
		//	printf("%s\n",d->d_name);
	}
	closedir(o);
	qsort(argar,i,sizeof(char *),compare);
	while (n < i)
		printf("%s\n",argar[n++]);

	return 0;
}
