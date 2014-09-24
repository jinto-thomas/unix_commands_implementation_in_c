#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#define SIZE 2048


int main(int argc,char **argv)
{
	char argar[SIZE];
	int n, pid,j,k,indx;
	int i = 0;
	char *newargar[SIZE];
	char *d;
	char  *temp[argc+1];

	n = read(0,argar,SIZE);
	argar[n] = '\0';

	j = 0;

	char del[] = {" ,\n,\t"};
	d = strtok(argar,del);

	while (d != NULL) {
		newargar[j++] = d;
		d = strtok(NULL,del);
	}
	newargar[j] = '\0';
	i = 0;
	k = 0;
	while (--argc > 0){
		temp[i++] = argv[++k];
		
	}
	k = j;

	while (--k >= 0) {
		temp[i++] = newargar[indx++];
		temp[i] = '\0';
		--i;
	
	
		pid = fork();

		if (pid == 0) {
			execvp(temp[0],temp);
		}	
		else
			wait(&pid);
	}
	return 0;

}
