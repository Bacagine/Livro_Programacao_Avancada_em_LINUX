#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
    char nome[50], sobrenome[50], completo[50];
    
    strcpy(nome, "bozo");
    strcpy(sobrenome, " da silva");
    strcpy(completo, nome);
    strcat(completo, sobrenome);
    
    printf("nome completo: %s\n", completo);
    
	return 0;
}

