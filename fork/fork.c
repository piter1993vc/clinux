#include <stdio.h>
#include <unistd.h>
int main(void){
int count1=0;
int count2=0;

int chippd;

printf("Before fork\n");
	sleep(5);
	chippd=fork();
if(chippd==0)
		{
		printf("This is a child process\n");
		while(count1 <10){
			printf("child process: %d\n",count1);
			sleep(1);
			count1++;
		}	
	}else{
		printf("Thi is the parrent process\n");
		while(count2<20){

		printf("parent process:%d\n",count2);
		sleep(1);
		count2++;
	}
}


return 0;		
}
