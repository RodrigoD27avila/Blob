KDIR  := /usr/src/linux-$(shell uname -r)
obj-m += hello.o

module:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	
