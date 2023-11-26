#include"headers.h"
#include"declerations.h"

static void __exit cleanup_func(void)
{

	#ifdef DEBUG
	printk(KERN_INFO " Begin: %s\n",__func__);
	#endif

	blk_cleanup_queue(bdev->queue);	

	vfree(bdev->data);
	kfree(bdev);
	unregister_blkdev(majorno,DEVNAME);

	#ifdef DEBUG
	printk(KERN_INFO "End: %s\n",__func__);
	#endif

}
module_exit(cleanup_func);
