/* captura.c: 
 * 
 * Compilar com: gcc captura.c -o captura
 *
 * OBS: Execute este programa como usuario root
 * 
 * Data: 30/07/2020
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <linux/tcp.h>
#include <linux/ip.h>
#include <linux/if.h>
#include <linux/if_ether.h>
#include <linux/sockios.h>

#define INTERFACE "eth0"

int main(void){
    int sock, rec_bytes, fromlen, pacotes;
    char buffer[65535];
    
    struct sockaddr_in from;
    struct tcphdr *tcp;
    struct iphdr *ip;
    struct ifreq ifr;
    
    sock = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    
    strncpy(ifr.ifr_name, INTERFACE, strlen(INTERFACE));
    
    if(ioctl(sock, SIOCGIFFLAGS, &ifr) == -1){
        perror("ioctl");
        exit(-1);
    }
    
    ifr.ifr_flags |= IFF_PROMISC;
    
    if(ioctl(sock, SIOCSIFFLAGS, &ifr) == -1){
        perror("erro do ioctl ");
        exit(-1);
    }
    
    pacotes = 10;
    
    while(pacotes){
        fromlen = sizeof from;
        rec_bytes = recvfrom(sock, buffer, sizeof buffer, 0,
                             (struct sockaddr *)&from, &fromlen);
        fprintf(stdout, "Bytes recebidos %5d\n", rec_bytes);
        fprintf(stdout, "Endereco de origem %s\n", inet_ntoa(from.sin_addr));
        
        ip = (struct iphdr *)buffer;
        tcp = (struct tcphdr *)(buffer + sizeof(struct iphdr));
        if(ip->protocol == 17)  fprintf(stdout, "Protocolo: UDP\n");
        if(ip->protocol == 1)   fprintf(stdout, "Protocolo ICMP\n");
        if(ip->protocol == 6){
            fprintf(stdout, "Protocolo TCP\n");
            fprintf(stdout, "Porta de origem %d\n", ntohs(tcp->source));
            fprintf(stdout, "Porta de destino %d\n\n", ntohs(top->dest));
        }
        memset(buffer, 0, 65535);
        pacotes--;
    }
    
    if(ioctl(sock, SIOCGIFFLAGS, &ifr) == -1){
        perror("Erro de ioctl");
        exit(-1);
    }
    
    ifr.ifr_flags &=~ IFF_PROMISC; // Desliga o modo promiscuo
    
    if(ioctl(sock, SIOCSIFFLAGS, &ifr) == -1){
        perror("ioctl set");
        exit(-1);
    }
    
    return 0;
}
