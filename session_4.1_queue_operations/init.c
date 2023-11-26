#include"headers.h"
#include"declerations.h"

int majorno,nsectors,hardsect_size;
struct Dev *bdev;

static int __init initialization_func(void)
{

	#ifdef DEBUG
	printk(KERN_INFO "Begin: %s\n", __func__);
	#endif
	
	majorno=MAJORNO;// macro is assigned to the global variable

	nsectors=NSECTORS;
	hardsect_size=HARDSECT_SIZE;

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
	#endif
	bdev=kmalloc(sizeof(struct Dev),GFP_KERNEL);
	if(!bdev)
	{
			
		#ifndef DEBUG
		printk(KERN_INFO "kmalloc() failed \n");
		#endif
		goto OUT;
	}
	bdev->size=nsectors*hardsect_size;
	bdev->data=vmalloc(bdev->size);
	if(!bdev->data)
	{
			
		#ifndef DEBUG
		printk(KERN_INFO "vmalloc() failed \n");
		#endif
		goto OUT;
	
	}
	
	spin_lock_init(&bdev->lock);
	

	bdev->queue=blk_init_queue(bdev_request,&bdev->lock);	
	if(!bdev->queue)
	{
			
		#ifndef DEBUG
		printk(KERN_INFO "blk_init_queue() failed \n");
		#endif
		goto OUT;
	
	}


	blk_queue_logical_block_size(bdev->queue, hardsect_size);
	 
	bdev->queue->queuedata=bdev;



	#ifdef DEBUG
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
