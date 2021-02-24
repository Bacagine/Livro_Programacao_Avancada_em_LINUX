#include <stdio.h>

int main(int argc, char **argv){
    int soma;
    float dinheiro;
    char letra;
    double pi;
    
    soma = 10;
    dinheiro = 2.21;
    letra = 'A';
    pi = 3.1416;
    
    fprintf(stdout, "valor de soma = %d\n", soma);
    fprintf(stdout, "valor de dinheiro = %f\n", dinheiro);
    fprintf(stdout, "valor de letra = %c\n", letra);
    fprintf(stdout, "valor de pi = %e\n", pi);

	return 0;
}

