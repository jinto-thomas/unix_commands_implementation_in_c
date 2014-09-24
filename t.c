#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int intcmp(const void *a,const void *b)
{
	return *(int *)a - *(int *)b;
}

int compare(const void *a, const void *b)
{
	const char *a1 = *(char **)a;
	const char *b1 = *(char **)b;
	return strcmp(a1,b1);
}
main()
{
		int i = 0;
		char *ar[] = {"hel","lo","app","as","roma","fc"};
		int a[] = {4,2,7,1,5};
		qsort(ar,6,sizeof(char*),compare);
		qsort(a,5,sizeof(int),intcmp);
		while (i < 6 )
			printf("%s\n",ar[i++]);
		i = 0;
		while (i < 5)
			printf("%d ",a[i++]);
		return 0;

		
}
