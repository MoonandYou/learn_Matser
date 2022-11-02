#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init hello_init(void)
{
    pr_info("hello world!\n");
    return 0;
}

static void __exit hello_exit(void)
{
    pr_info("goodbye cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_AUTHOR("hang <Qq1418046168@outlook.com>");
MODULE_LICENSE("GPL");