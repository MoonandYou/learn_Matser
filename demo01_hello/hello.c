#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/wait.h>
#include <linux/poll.h>
#include <linux/sched.h>
#include <linux/slab.h>

#define    OK            0
#define    ERROR        -1

dev_t devNum;
int reg_major = 232;
int reg_minor = 0;
unsigned int subDevNum = 1;

struct cdev *mdev;
struct file_operations *mfile;


int hello_open(struct inode *p, struct file *f)
{
    printk(KERN_INFO"hello open\n");
    return 0;
}

ssize_t hello_read(struct file *f, char __user *u,
        size_t s, loff_t *l)
{
    printk(KERN_INFO"hello read\n");
    return 0;
}

ssize_t hello_write(struct file *f, const char __user *u,
        size_t s, loff_t *l)
{
    printk(KERN_INFO"hello write\n");
    return 0;
}

int hello_init(void)
{
    devNum = MKDEV(reg_major, reg_minor);
    if (register_chrdev_region(devNum, subDevNum, "helloworld")) {
        printk(KERN_ERR"register_chrdev_region error!\n");
        return ERROR;
    }
    printk(KERN_INFO"hello driver init.\n");
    mdev = kzalloc(sizeof(struct cdev), GFP_KERNEL);
    mfile = kzalloc(sizeof(struct file_operations), GFP_KERNEL);

    mfile->open = hello_open;
    mfile->read = hello_read;
    mfile->write = hello_write;
    mfile->owner = THIS_MODULE;

    cdev_init(mdev, mfile);
    cdev_add(mdev, devNum, 1);
    return 0;
}

void __exit hello_exit(void)
{
    printk(KERN_INFO"hello driver exit.\n");
    cdev_del(mdev);

    kfree(mdev);
    kfree(mfile);
    unregister_chrdev_region(devNum, subDevNum);
    return;
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_LICENSE("GPL");