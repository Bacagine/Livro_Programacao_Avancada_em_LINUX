/*
 * server UDP
 * 
 * Compilar com: gcc UDPServer.c -o UDPServer
 * 
 * Data: 30/07/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <arpa/inet.h>
#include <syslog.h>
#include <signal.h>

#define PORT   1200
#define BUFLEN 512 // buffer

int main(void){
    int sockfd;
    
    struct sockaddr_in local_addr;
    struct sockaddr_in remote_addr;
    
    int addr_len, numbytes;
    char buf[BUFLEN];
    
    if(){
        
    }
    
    /* INSERIR O QUE FALTA AQUI */
    
    if(){
        
    }
    
    /* Inserir o que falta aqui */
    
    while(1){
        /* Inserir o que falta aqui */
    }
    
    close(sockfd);
    
    return 0;
}
