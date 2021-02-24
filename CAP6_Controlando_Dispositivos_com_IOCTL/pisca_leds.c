/*
 * pisca_leds.c: pisca os leds do teclado
 * 
 * Compilar com: gcc pisca_leds.c -o pisca_leds
 * 
 * Data: 30/07/2020
 */

#include <sys/ioctl.h>
#include <linux/kd.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
    int leds = 0;
    
    /* Loop variado os 3 bits mais baixos de leds */
    while(1){
        leds = 2 * leds + 1;
        if(leds & 8){
            leds ^= 9;
        }
        if(ioctl(0, KDSETLED, leds)){
            exit(1);
        }
        sleep(1);
    }
    
    return 0;
}

