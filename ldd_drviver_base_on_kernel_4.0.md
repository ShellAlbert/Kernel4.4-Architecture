# 字符型设备  123258789  
struct cdev  
copy_to_user 从内核空间复制数据到用户空间  
copy_from_user 从用户空间复制数据到内核空间  
struct file *filp 该结构体中的private_data指针可用于保存一些用户自定义的地址  
字符设备函数操作集合  
struct file_operations  
.owner .read .write .ioctl .open .release  
设备号 dev_t devno=MKDEV(major,minor)  
申请设备号  
register_chrdev_region(struct cdev*,int,char*)  
注销设备号  
unregister_chrdev_region  
初始化字符设备  
cdev_init(struct cdev* ,struct file_operations*)  
将字符设备添加到系统中  
cdev_add(struct cdev* , devno,1)  
从内核中删除  
cdev_del  
内存kmalloc/kfree   

kernel4.4的内核架构较之前2.6的有了很大的改变  
复杂性增大，故还是使用原始的方法直接操作寄存器来操作i2s  
抛弃内核自己抽像出来的框架，这样来得简单快速  
首先需要将物理地址映射到虚拟地址，验证访问是否正确  
其他再就是要确认好RxFIFO的中断号，这个很关键  

