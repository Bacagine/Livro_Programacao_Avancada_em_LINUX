/* Indica que estamos dentro do kernel
 * faz diferença na compilação de certos include files
 */

#define __KERNEL__
#define MODULE                 /* Necessário para indicar que é um módulo */
#include <linux/module.h>      /* Todos os símbolos e estruturas */

/* Função que é chamada ao carregamento do módulo */
int init_module(void){
    printk("<1> Hello World!\n");
    
	return 0;
}

/* Função chamada quando da remoção do mesmo */

void cleanup_module(void){
    printk("<1> Tchau :~D\n");
}

