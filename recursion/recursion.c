#include <stdio.h>

int accumulate(int a){
int ret;
	a=a*2+2;

		if(a<100)
			ret=accumulate(a);
		else 
			ret=a;
	printf("a= %i\n",a);
	return ret;

}
int main(){
int a=1;
int ret;
	ret=accumulate(a);

printf("ret =%i\n",ret);

return 0;
}

