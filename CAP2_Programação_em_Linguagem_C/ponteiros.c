#include <stdio.h>

int main(int argc, char **argv){
    int a = 10;    /* declare a sendo um int, inicializando com o valor 10 */
    int *b;       /* declare b como contendo um ponteiro para um dado do tipo int */
    
    b = &a;      /* o caractere & faz o contrario de *, ou seja, apresentao
                    endereço da variavel. */
    printf("a é igual a: %d\n", a);
    printf("b é igual a: %d\n", *b);    /* devemos desreferenciar b para imprimir
                                           seu conteudo */
    
    *(b) = 20;       /* o conteudo de b deve ser 20. Lembre-se que b aponta para o
                       mesmo endereço que a. Poderia ser escrito sem os parenteses,
                       mas eles servem para destacar a operação */
    
    printf("a é igual a: %d\n", a);
    printf("b é igual a: %d\n", *b);

	return 0;
}

