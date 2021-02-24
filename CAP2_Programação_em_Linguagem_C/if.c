#include <stdio.h>

int main(int argc, char **argv){
    int x;
    while(1){ /* faz um loop sem fim */
        printf("x = %d\n", x);
        x = x - 1;
        if(x > 10){
            break; /* se x for maior que 10, sai do loop */
        }
        else{
            printf("continuando...\n");
        }
    }
    printf("Saindo...\n");
    
	return 0;
}

