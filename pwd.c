#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char arr[100];
	char *name;

	name = getcwd(arr,sizeof(arr));
	printf("%s\n",name);

	return 0;
}
