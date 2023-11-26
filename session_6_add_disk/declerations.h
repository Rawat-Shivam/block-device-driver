
extern int majorno,nsectors;
extern short hardsect_size;

extern int nominors, minorno;

struct Dev 
{
	int size;
	u8 *data;
	short users;
	
	int count;

	int nsectors;

	spinlock_t lock;
	struct request_queue *queue;

	struct gendisk *gd;
		
	struct block_device bdev;
};

extern struct Dev *bdev;
void bdev_request(struct request_queue *);

// [vim /usr/src/kernels/linux-4.16.9/include/linux/fs.h]
//extern int register_blkdev(unsigned int, const char *);
//extern void unregister_blkdev(unsigned int, const char *);


int bdev_open(struct block_device *, fmode_t);
//int (*open) (struct block_device *, fmode_t);

