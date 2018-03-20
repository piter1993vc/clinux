#include <stdio.h>
int main(void){


int a[10]={2,2,3,3,4,5,6,7,8,9};

	int i,j,n;
	for( i=9;i>0;i--){
		for(j=0;j<i;j++){
		if(a[j]<a[j+1]){
		n=a[j];
		a[j]=a[j+1];
		a[j+1]=n;	

		}
		}
	}
for(i=0;i<10;i++)
	printf("a[i] =%i\n",a[i]);


return 0;
}
