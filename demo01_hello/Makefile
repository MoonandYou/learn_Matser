ifneq ($(KERNELRELEASE),)
obj-m := hello.o
else
PWD :=$(shell pwd)
#KDIR := /home/hang/workspace/linux-4.9.229
KDIR := /lib/modules/`uname -r`/build

all:
	make -C $(KDIR) M=$(PWD)
clean:
	rm -rf *.o *.ko *.mod.c *.symvers *.c~ *~
endif