#include"headers.h"
#include"declerations.h"

static void __exit cleanup_func(void)
{

	#ifdef DEBUG
	printk(KERN_INFO " Begin: %s\n",__func__);
	#endif

	unregister_blkdev(majorno,DEVNAME);

	#ifdef DEBUG
	printk(KERN_INFO "End: %s\n",__func__);
	#endif

}
module_exit(cleanup_func);
