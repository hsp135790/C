/*
filename, server_ipadress portno

argv[0] = filename
argv[1] = server_ipadress
argv[2] = portno

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> //Header file for func read, write, close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> //This defines hostnet structure

void error(const char *msg)
{
	perror(msg);
	exit(0);
}

int main(int argc, char *argv[])
{
	int sockfd, portno, n;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	
	char buffer[255];
	
	if(argc < 3)
	{
		fprintf(stderr, "usage %s hostname port\n",argv[0]);
		exit(1);
	}
	
	portno = atoi(argv[2]);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
		error("ERROR on opening socket.");
		
	server = gethostbyname(argv[1]);
	if(server == NULL)
	{
		fprintf(stderr, "ERROR, no such host");
	}
	
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr , server->h_length);
	serv_addr.sin_port = htons(portno);
	
	if(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		error("Connection failed.");
		
		
	while(1)
	{
		int num1, num2, ans, choice;
	
	//enter num1
	
		bzero(buffer,255);
      		n = read(sockfd, buffer, 255); //Read server string
      		if(n < 0)
      			error("ERROR on reading from the socket.");
      		printf("Server : %s\n",buffer);
      		scanf("%d",&num1);
      		write(sockfd, &num1, sizeof(int)); //Send num1 to Server
      	
      	
      	//num2
      		bzero(buffer,255);
      		n = read(sockfd, buffer, 255); //Read server string
      		if(n < 0)
      			error("ERROR on reading from the socket.");
      		printf("Server : %s\n",buffer);
      		scanf("%d",&num2);
      		write(sockfd, &num2, sizeof(int)); // Send num2 to server
      	
      	
      	//choice
      		bzero(buffer, 255);
      		n = read(sockfd, buffer, 255);
      		if(n < 0)
      			error("ERROR on reading from the socket.");
      		printf("Server : %s\n",buffer);
      		scanf("%d",&choice);
      		write(sockfd, &choice, sizeof(int));
      	

      	 
      		
      		
      		if(choice == 5)
      		 break;
      		
      		read(sockfd, &ans, sizeof(int));
      		printf("Server - The answer is : %d\n",ans);
      		
      		
	}	
	
      	
      	
      		
      	
	printf("You have selected to exit. Exit Successful.");
	
	close(sockfd);
	return 0;
}



