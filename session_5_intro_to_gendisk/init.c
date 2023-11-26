#include"headers.h"
#include"declerations.h"

int majorno, minorno, nominors, nsectors;
short hardsect_size;
struct Dev *bdev;

static int __init initialization_func(void)
{

	#ifdef DEBUG
	printk(KERN_INFO "Begin: %s\n", __func__);
	#endif
	

	majorno=MAJORNO;// macro is assigned to the extern variable

	minorno=MINORNO;
	nominors=NOMINORS;

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
	printk( KERN_INFO " Majorno : %d\n",majorno);
	#endif


	bdev=kmalloc(sizeof(struct Dev),GFP_KERNEL);
	if(!bdev)
	{
			
		#ifndef DEBUG
		printk(KERN_INFO "kmalloc() failed \n");
		#endif
		goto OUT;
	}
	bdev->size=nsectors * hardsect_size;
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
	bdev->nsectors=nsectors;
	
	bdev->gd=alloc_disk(nominors);//dev->gd=alloc_disk(1);
	//dev->gd=alloc_disk(16);// what ot give 1 or 16 and when 
	if(!bdev->gd)
	{
		#ifndef DEBUG
		printk(KERN_INFO "blk_init_queue() failed \n");
		#endif
		goto OUT;
	}

		
	bdev->gd->major=;
	bdev->gd->first_minor=0;
	bdev->gd->minors=4;//16 why and when to use
	bdev->gd->fops=&bops;
	bdev->gd->queue=bdev->queue;
	bdev->gd->private_data=bdev;
	sprintf(bdev->gd->disk_name,"%s",DEVNAME);
	set_capacity(dev->gd,bdev->nsectors);




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
