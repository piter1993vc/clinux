#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){

char *ptr;
ptr=(char*) malloc(24);

	if(ptr==NULL){
		printf("Failed to get or allocate memory\n");

	}	
	strcpy(ptr,"Hello there!");
	printf("ptr: %s",ptr);
	free(ptr);
return 0;

}
