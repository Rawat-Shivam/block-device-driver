
extern int majorno,nsectors,hardsect_size;


struct Dev 
{
	int size;
	u8 *data;
	short users;

	spinlock_t lock;
	struct request_queue *queue;
	
};

extern struct Dev *bdev;
void bdev_request(struct request_queue *);




// [vim /usr/src/kernels/linux-4.16.9/include/linux/fs.h]
//extern int register_blkdev(unsigned int, const char *);
//extern void unregister_blkdev(unsigned int, const char *);

