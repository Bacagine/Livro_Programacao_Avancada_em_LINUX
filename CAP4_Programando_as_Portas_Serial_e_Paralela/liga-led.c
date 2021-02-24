/* Ferramenta para ligar os leds na porta parelela
 * liga-led <valor>, aonde valor vai de 0 a 255
 * lembre-se do valor em binario antes:
 * 0 0 0 0 0 0 0 0 -> para cada posição um led sera acesso. A combinação
 * das posições vai gerar um decimal que deve ser usado como parametro
 * 
 * compilar com gcc liga-led.c -o liga-led -O2
 * 
 */

#include <stdio.h>
#include <sys/io.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEDS 8        /* número de bits */
#define LPTPORT 0X3BC    /* endereço da porta */

int main(int argc, char **argv){
    unsigned char lights, i;
    
    if(argc < 2){
        fprintf(stderr, "Falta o parametro\n\n!");
        fprintf(stderr, "liga-led <número>\nonde número é ");
        fprintf(stderr, "o valor decimal correspondente aos leds ");
        fprintf(stderr, " que devem ser ativos, em um byte \n");
        exit(0);
    }
    
    if(ioperm(LPTPORT, 1, 1)){
        fprintf(stderr,"ioperm error.\n");
        exit(1);
    }
    
    i = 0
    lights = atoi(argv[1]);;
    outb(lights, LPTPORT);
    
}

