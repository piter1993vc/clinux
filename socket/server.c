#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>


int main(int argc,char *argv[]){

/*variables*/
	int sock;
	int ret;
	struct sockaddr_in server;
	int mysock;
	char buffer[1024];

/*create socket*/
	sock=socket(AF_INET,SOCK_STREAM,0);
	if(sock<0){
		perror("Failed create socket");
		exit(1);
	}

	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port=htons(5000);

/*call bind*/
	if(bind(sock,(struct sockaddr *)&server,sizeof(server)))
	{
		perror("Error bind");
		exit(1);
	}

/*listening*/
	listen(sock,5);

/*accept*/
	do {
		mysock=accept(sock,(struct sockaddr *)0,0);
		if(mysock==-1){
			perror("accept failed");
		}else{
			memset(buffer,0,sizeof(buffer));
			if(ret=recv(mysock,buffer,sizeof(buffer),0)<0){
				perror("error reading stream message");
			}else if(ret==0){
				printf("Ending information\n");
			}
			else{
				printf("MSG: %s \n",buffer);
				printf("Got to message:  ( rval = %d)\n",ret);
			}	

		}

	}while(1);

return 0;

}
