#include"headers.h"
#include"declerations.h"

int bdev_open(struct block_device *fbdev, fmode_t fmode)
{
//	struct Dev *ldev;//local Dev;
	#ifdef DEBUG
	printk(KERN_INFO "Begin: %s\n",__func__);
	#endif
/*
 * ldev = container_of(fbdev->bd_inode->ibdev, struct Dev, bdev);
	if(!ldev)
	{
		#ifdef DEBUG
		printk(KERN_ERR "ERROR: Container_of() failure");
		#endif

		goto OUT;
	}
*/
	#ifdef DEBUG
	printk(KERN_INFO "End: %s\n",__func__);
	#endif

	return 0;

OUT:
	#ifdef DEBUG
	printk(KERN_INFO "ERROR: End: %s\n",__func__);
	#endif
	
	return -1;


}
