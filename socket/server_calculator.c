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
		int num1, num2, ans, choice, cnt=0;
	
	
		n = write(newsockfd, "Enter number 1 : ", strlen("Enter number 1 : ")); //ask for num1
		if(n < 0)
			error("ERROR writing on socket");
		
		read(newsockfd, &num1, sizeof(int));
		printf("Client Number 1 is : %d\n",num1);
	
	
		n = write(newsockfd, "Enter number 2 : ", strlen("Enter number 2 : ")); //ask for num1
		if(n < 0)
			error("ERROR writing on socket");
		
		read(newsockfd, &num1, sizeof(int));
		printf("Client Number 2 is : %d\n",num2);
	
		n = write(newsockfd, "Enter your choice : \n1.Add\n2.Substraction\n3.Multiplication\n4.Division\n5.Exit\n",strlen("Enter your choice : \n1.Add\n2.Substraction\n3.Multiplication\n4.Division\n5.Exit\n"));
	
		read(newsockfd, &choice, sizeof(int));
		printf("Choice is : %d\n", choice);
	
		switch(choice)
		{
			case 1: 
				ans = num1 + num2;
			
			case 2:
				ans = num1 - num2;
			
			case 3: 
				ans = num1*num2;
		
			case 4:
				ans : num1/num2;
			
			case 5:
				break;
		}
	
		if(choice == 5)
			break;
		
	}
		
	

	
	
	close(newsockfd);
	close(sockfd);
	return 0;
	
}



