#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#define DATA "SENDMESSAGE"
int main(int argc,char * argv[]){
	int sock;
	struct sockaddr_in server;
	char buffer[1024];
	struct  hostent *hp;
/*create socket*/
        sock=socket(AF_INET,SOCK_STREAM,0);
        if(sock<0){
                perror("Failed create socket\n");
                exit(1);
        }

        server.sin_family=AF_INET;			
	hp=gethostbyname(argv[1]);
	if(hp==0){
		perror("Get host by name error\n");
		exit(1);
	}

	memcpy(&server.sin_addr,hp->h_addr,hp->h_length);
	server.sin_port=htons(5000);	
	if(connect(sock,(struct sockaddr *)&server,sizeof(server))<0){
		perror("Connect filed\n");
		close(sock);
		exit(1);

	}
	if(send(sock,DATA,sizeof(DATA),0)<0){
		perror("send failed\n");
		close(sock);
		exit(1);
	}
	printf("send data: %s\n",DATA);
	close(sock);


return 0;
}
