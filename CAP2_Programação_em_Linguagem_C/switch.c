#include <stdio.h>

int main(int argc, char **argv){
    int x;
    while(1){ /* faz um loop sem fim */
        printf("x = %d\n", x);
        x = x - 1;
        switch(x){
            case 10:
                printf("x chegou a 10\n");
                break;
            case 20:
                printf("x chegou a 20\n");
                break;
            default:
                printf("incrementando x\n");
                break;
        } /* switch */
        if(x > 30){
            printf("x maior que 30, saindo do loop...\n");
            break;
        } /* if */
    } /* while */
    
	return 0;
}

