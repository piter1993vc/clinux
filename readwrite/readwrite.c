#include <stdio.h>
#include <unistd.h>

int main ( void){
int ret;
char buffer[20];
while(1){

ret=read(0,buffer,20);
printf("ret=%d\n",ret);
if(ret<20){
	printf("%s\n",buffer);
	break;
	}
	else{
	printf("%s\n",buffer);
}

}




return 0;
}
