#define __KERNEL__
#define MODULE

#include <linux/module.h>
#include <sys/syscall.h>
#define NULLO
extern void* sys_call_table[];

int (*origin_unlink)(char *path);

int new_

