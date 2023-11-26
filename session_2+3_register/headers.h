#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("RAWAT_SHIVAM");
MODULE_DESCRIPTION("BLOCK DD Registration");

#ifndef DEBUG
#define DEBUG
#endif

#ifndef DEVNAME
#define DEVNAME "blockDriver"
#endif

#ifndef MAJORNO
#define MAJORNO 0
#endif 


