#include<linux/init.h>
#include<linux/module.h>
#include<linux/fs.h>
#include<linux/slab.h>
#include<linux/vmalloc.h>
#include<linux/spinlock.h>
#include<linux/blkdev.h>


MODULE_LICENSE("GPL");
MODULE_AUTHOR("RAWAT_SHIVAM");
MODULE_DESCRIPTION("initializing request Queue");

#ifndef DEBUG
#define DEBUG
#endif

#ifndef DEVNAME
#define DEVNAME "BlockDriver"
#endif

#ifndef MAJORNO
#define MAJORNO 0
#endif 


#ifndef MINORNO
#define MINORNO 0
#endif 




#ifndef NOMINORS
#define NOMINORNOS 1
#endif 



#ifndef NSECTORS
#define NSECTORS 512
#endif

#ifndef HARDSECT_SIZE
#define HARDSECT_SIZE 4096
#endif
