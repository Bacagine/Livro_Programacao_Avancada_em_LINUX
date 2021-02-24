/* chardev.c
 * Copyright Original (C) 1998-1999 by Ori Pomerantz
 * boacabelo.c
 * Adaptação Gleico S. Moraes 2003 p/ 2.4.x
 * Criaum char device, read only
 */

#define __KERNEL__           // parte do kernel
#define MODULE

/* Header files */

#include <linux/module.h>
#include <linux/fs.h>

#include <asm/uaccess.h>

/* 
 * 
 * 
 * 
 */
