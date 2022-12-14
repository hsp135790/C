#include <stdio.h>
#include <stdlib.h> // int atoi(const char *str) -> Converts the string pointed to, by the argument str to an integer(type int). portno to integer
#include <string.h>
#include <unistd.h>
#include <sys/types.h> //This contains definitions of a number of data types used in system calls, also this executes sys/socket.h netinet/in.h
#include <sys/socket.h> //This includes a number of a definitions of structures needed for sockets Eg:defines the sockaddr structure
#include <netinet/in.h> // This contains constants and structures needed for internet domain addresses Eg: sockaddr_in

void error(const char *msg)
{
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		fprintf(stderr, "ERROR, Port no not provided.\n");
		exit(1);
	}
	
	int sockfd, newsockfd, portno, n;
	char buffer[255];
	
	struct sockaddr_in serv_addr, cli_addr;
	socklen_t clilen; //socklen_t -> 32bit data type, socket.h
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0)
	{
		error("ERROR opening Socket.");
	}
	
	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno = atoi(argv[1]);
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno); //host to network shots
	
	if(bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
		error("Binding Failed");
		
	listen(sockfd, 5);
	clilen = sizeof(cli_addr);
	
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	
	if(newsockfd < 0)
		error("ERROR on Accept.");
		
	while(1)
	{
		bzero(buffer, 255);
		n = read(newsockfd, buffer,255);
		
		if(n < 0)
			error("ERROR on reading");
			
		printf("Client : %s\n",buffer);
		bzero(buffer, 255);
		fgets(buffer, 255, stdin);
		
		n = write(newsockfd, buffer, strlen(buffer));
		if(n < 0)
			error("ERROR on writing.");
			
		int i = strncmp("Bye", buffer, 3); // 3 : strlen(buffer)
		if(i == 0)
			break;
	}
	
	close(newsockfd);
	close(sockfd);
	return 0;
	
}



