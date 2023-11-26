#include"headers.h"
#include"declerations.h"

int majorno;

static int __init initialization_func(void)
{

	#ifdef DEBUG
	printk(KERN_INFO "Begin: %s\n", __func__);
	#endif
	
	majorno=MAJORNO;// macro is assigned to the global variable

	majorno=register_blkdev(majorno,DEVNAME);
	if(majorno < 0)
	{
		#ifndef DEBUG
		printk(KERN_INFO "register_blkdev() failed \n");
		#endif
		goto OUT;
	}

	#ifdef DEBUG
	printk( KERN_INFO " majorno : %d\n",majorno);
	printk(KERN_INFO "end: %s\n", __func__);
	#endif
	return 0;

OUT:
	#ifndef DEBUG
	printf(KERN_INFO "End[ERROR]: %s\n", __func__);
	#endif
	return -1;

}

module_init(initialization_func);
