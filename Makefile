obj-m += fpga_i2s.o
build:
	make ARCH=arm64 CROSS_COMPILE=aarch64-linux-gnu- -C ../kernel M=$(shell pwd) modules
	aarch64-linux-gnu-gcc test.c  -o test64.bin
.PHONY clean:
clean:	
	rm -rvf *.mod.* *.o modules.* Module.* *.ko 
	rm -rvf test64.bin
