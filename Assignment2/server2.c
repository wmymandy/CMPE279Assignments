// Server side C/C++ program to demonstrate Socket programming 
#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <sys/wait.h>
#define PORT 80
#define BUF_SIZE 100
int main(int argc, char const *argv[]) 
{ 
    //int server_fd, new_socket, valread; 
	printf("in server2! yeah!!\n");
    int new_socket = atoi(argv[1]);
    char buffer[1024] = {0}; 
    char *hello = "Hello from server"; 
    // Process under children process
    // Drop privileges to "nobody" user
    if (setuid(65534) != 0) {
        perror("fail to drop privileges\n");
        exit(EXIT_FAILURE);
    }
    // Check if privileges dropped permanently
    if (setuid(0) != -1) {
        perror("privileges is able to restore\n");
        exit(EXIT_FAILURE);
    }
	printf("uid after driop privillege %d\n",getuid() );

        int valread = read( new_socket , buffer, 1024);
        printf("%s\n",buffer );
        send(new_socket , hello , strlen(hello) , 0 );
        printf("Hello message sent from exec server\n");
      

    return 0; 
} 