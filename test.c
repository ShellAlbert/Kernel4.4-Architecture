#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
int main(void)
{
	int ret;
	char pcmBuffer[1024];
	int fd=open("/dev/fpga-i2s",O_RDONLY);
	if(fd<0)
	{
		printf("failed to open fpga-i2s.\n");
		return -1;
	}
	ret=read(fd,pcmBuffer,sizeof(pcmBuffer));	
	close(fd);
	return 0;
}
