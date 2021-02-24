#include <stdio.h>

int soma(int a, int b);

int main(int argc, char **argv){
    int x, y, z;
    
    fprintf(stdout, "Digite o primeiro número: ");
    scanf("%d", &x);
    fprintf(stdout, "Digite o segundo número: ");
    scanf("%d", &y);
    
    z = soma(x, y);
    
    fprintf(stdout, "A soma de %d com %d é %d\n", x, y, z);
    
	return 0;
}

int soma(int a, int b){
    return (a + b);
}

