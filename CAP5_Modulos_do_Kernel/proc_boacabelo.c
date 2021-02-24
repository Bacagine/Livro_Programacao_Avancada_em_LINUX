#define MODULE
#define __KERNEL__

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <asm-generic/uaccess.h>
#define MODULE_NAME "BoaCabelo"     // o nome do diretório /proc/BoaCabelo
#define MODULE_VERSION "0.1"        // Uma versão para o nosso módulo

static struct proc_dir_entry *boacabelo_dir, *jiffies_file;

static int boacabelo_read(char *page, char **start, off_t, int count,
    int *eof, void *data){
        
    int len;
    
    MOD_INC_USE_COUNT;
    
    len = sprintf(page, "jiffies = %ld\n", jiffies);
    
    MOD_DEC_USE_COUNT
    
    return len;
    
}

static int __init init_procfs_example(void){
    
    /* Cria um diretório */
    boacabelo_dir = proc_mkdir (MODULE_NAME, NULL);
    if(boacabelo_dir == NULL){
        return -ENOMEM;
    }
    boacabelo_dir->owner = THIS_MODULE;
    
    /* cria um arquivo chamado jiffies usando uma função rápida */
    
    jiffies_file = creat_proc_read_entry("jiffies, \
                        0444, boacabelo_dir, \
                        boacabelo_read, NULL");
    if(jiffies_file == NULL){
        remove_proc_entry("tty", boacabelo_dir);
        return - ENOMEM;
    }
    jiffies_file->owner = THIS_MODULE;
    
    printk(KERN_INFO "%s %s carregando\n", MODULE_NAME, MODULE_VERSION);
    return 0;
}

static void __exit cleanup_procfs_example(void){
    remove_proc_entry("jiffies", boacabelo_dir);
    remove_proc_entry(MODULE_NAME, NULL);
    printk(KERN_INFO "%s %s removido\n", MODULE_NAME, MODULE_VERSION);
}

/* Macros */

module_init (init_procfs_example);      // função de início do módulo
module_exit(cleanup_procfs_example);    // função de limpeza (remoção)

MODULE_DESCRIPTION("Exemplo procfs ");   // Nome

EXPORT_NO_SYMBOLS;       // Indica que nenhum símbolo externo deve ser expertado

