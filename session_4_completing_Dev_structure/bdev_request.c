#include"headers.h"
#include"declerations.h"

void bdev_request(struct request_queue *queue)
{

	#ifdef DEBUG
	printk(KERN_INFO "BEGIN: %s\n",__func__);
	#endif




	#ifdef DEBUG
	printk(KERN_INFO "END: %s\n",__func__);
	#endif

}

