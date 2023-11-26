#include"headers.h"
#include"declerations.h"

static void __exit cleanup_func(void)
{

	#ifdef DEBUG
	printk(KERN_INFO " Begin: %s\n",__func__);
	#endif

//here it should not be used ,.....but later
//because it can only be deleted after it is added
//del_gendisk(bdev->gd);

	blk_cleanup_queue(bdev->queue);	

	vfree(bdev->data);
	kfree(bdev);
	unregister_blkdev(majorno,DEVNAME);

	#ifdef DEBUG
	printk(KERN_INFO "End: %s\n",__func__);
	#endif

}
module_exit(cleanup_func);
