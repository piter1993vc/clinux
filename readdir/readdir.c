#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
int main(void){
struct dirent *sd;
DIR * dir;
	dir=opendir(".");
	if(dir==NULL){
	printf("cos sie zjebalo\n");
	exit(1);
	}	

	while((sd=readdir(dir))!=NULL){
		printf(">> %s\n",sd->d_name);

	}
	closedir(dir);
	
return 0;
}
