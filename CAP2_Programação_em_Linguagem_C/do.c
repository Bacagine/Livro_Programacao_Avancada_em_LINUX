#include <stdio.h>

int main(int argc, char **argv){
    int x;
    do{
        printf("x = %d\n", x);
        x = x - 1;
    }while(x > 0);

	return 0;
}

